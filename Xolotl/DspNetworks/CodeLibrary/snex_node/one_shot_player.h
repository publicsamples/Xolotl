template <int NV> struct one_shot_player: public data::base
{
    SNEX_NODE(one_shot_player);



    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;

    // Pitch in semitones (-12 .. +12)
    double pitchSemitones = 0.0;
    double grainMs = 50.0;      // grain size in milliseconds
    double grainSize = 2048.0; // samples
	
    // Freeze + scrub
    bool freeze = true;
    double scrub = 0.0;   // 0..1

    // Loop
    bool loop = false;

    // MIDI root note
    int rootNote = 60;

	double scanPhase = 0.0;
	//double smoothScrub = 0.0;
	
	void updateGrainSize()
	{
	    if (sr <= 0.0)
	        return;
	
	    grainSize = (grainMs * sr) * 0.001;
	
	    // safety clamp
	    if (grainSize < 8.0)
	        grainSize = 8.0;
	
	    if (grainSize > (double)data.numSamples - 2.0)
	        grainSize = (double)data.numSamples - 2.0;
	}
	
	inline double hann(double x)
	{
	    // x = 0..1
	    return 0.5 - 0.5 * Math.cos(2.0 * Math.PI * x);
	}
	
    struct VoiceData
    {
        double uptime = 0.0;   // read position
        double delta = 1.0;    // playback speed
        int noteNumber = 60;

        void reset()
        {
            uptime = 0.0;
        }
    };

    PolyData<VoiceData, NV> voiceData;

    void prepare(PrepareSpecs ps)
    {
        voiceData.prepare(ps);
        sr = ps.sampleRate;
    }

    void reset()
    {
        for (auto& v : voiceData)
            v.reset();
    }

 void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
{
    double pos = 0.0;

    if (freeze)
    {
        double maxStart = (double)data.numSamples - grainSize - 2.0;
        if (maxStart < 0.0)
            return;

        double startPos = scrub * maxStart;
        pos = startPos + v.uptime;

        v.uptime += v.delta;

        if (v.uptime >= grainSize)
            v.uptime -= grainSize;
    }
    else
    {
        pos = v.uptime;
        v.uptime += v.delta;

        if (pos >= (data.numSamples - 1))
        {
            if (loop)
            {
                v.uptime = 0.0;
                pos = 0.0;
            }
            else
            {
                return;
            }
        }
    }

    // --- interpolation ---
    int iPos = (int)pos;
    int iNext = iPos + 1;
    if (iNext >= data.numSamples)
        iNext = data.numSamples - 1;

    double frac = pos - (double)iPos;

    for (int ch = 0; ch < NUM_CHANNELS; ch++)
    {
        float s0 = sample[ch][iPos];
        float s1 = sample[ch][iNext];
        double winPhase = v.uptime / grainSize;
        double win = hann(winPhase);
        fd[ch] += (float)((1.0 - frac) * s0 + frac * s1);
    }
}


    template <typename ProcessDataType>
    void process(ProcessDataType& pd)
    {
        if (data.numSamples == 0)
            return;

        DataReadLock sl(data);
        auto& v = voiceData.get();
        auto fd = pd.toFrameData();

        while (fd.next())
            processInternal(fd.toSpan(), v);

        data.setDisplayedValue(v.uptime);

        bool isPlaying = (int)v.uptime < data.numSamples;
        gate.setModValueIfChanged((double)isPlaying);
    }

    void processFrame(span<float, NUM_CHANNELS>& fd)
    {
        if (data.numSamples == 0)
            return;

        DataReadLock sl(data);
        auto& v = voiceData.get();
        processInternal(fd, v);
    }

    // MIDI note handling
    void handleHiseEvent(HiseEvent& e)
    {
        if (e.isNoteOn())
        {
            auto& v = voiceData.get();
            v.reset();
            v.noteNumber = e.getNoteNumber();

            double midiSemis = (double)(v.noteNumber - rootNote);
            double totalSemis = midiSemis + pitchSemitones;
            double pitchMult = Math.pow(2.0, totalSemis / 12.0);

            if (sr > 0.0)
                v.delta = (data.sampleRate / sr) * pitchMult;
        }
    }

    void updateDelta()
    {
        if (data.numSamples == 0 || sr == 0.0)
            return;

        for (auto& v : voiceData)
        {
            double midiSemis = (double)(v.noteNumber - rootNote);
            double totalSemis = midiSemis + pitchSemitones;
            double pitchMult = Math.pow(2.0, totalSemis / 12.0);

            v.delta = (data.sampleRate / sr) * pitchMult;
        }
    }

 void setExternalData(const ExternalData& ed, int index)
{
    data = ed;

    ed.referBlockTo(sample[0], 0);
    ed.referBlockTo(sample[1], 1);

    updateDelta();
    updateGrainSize();
    reset();
}

    ModValue gate;

    bool handleModulation(double& value)
    {
        return gate.getChangedValue(value);
    }

    template <int P>
    void setParameter(double v)
    {
        // Pitch: 0..1 → -12..+12
        if (P == 0)
        {
            pitchSemitones = (v * 24.0) - 12.0;
            updateDelta();
        }

        // Loop
        if (P == 1)
        {
            loop = (v > 0.5);
        }

        // Freeze
        if (P == 2)
        {
            freeze = (v > 0.5);
        }

        // Scrub
        if (P == 3)
        {
            scrub = v;
            data.setDisplayedValue(scrub);
        }
        

        // 0..1 → ~20ms .. ~500ms (musical)
        // Grain size in milliseconds (direct input from UI)
        if (P == 4)
        {
            grainMs = v;   // v is already an exact millisecond value
            updateGrainSize();
        }
    }
    
};
