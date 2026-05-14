template <int NV>
struct one_shot_player: public data::base
{
    SNEX_NODE(one_shot_player);



    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;

    // Playback ratio multiplier, matching HISE-style FreqRatio behaviour.
    double pitchRatio = 1.0;
    double grainMs = 50.0;      // grain size in milliseconds
    double grainSize = 2048.0; // samples
	
    // Freeze + scrub
    bool freeze = true;
    double scrub = 0.0;   // 0..1
    int scrubMode = 0;    // 0 = latch, 1 = zero-crossing latch

    // Loop
    bool loop = false;
    double loopStart = 0.0; // 0..1
    double loopEnd = 1.0;   // 0..1

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

    inline double clamp01(double x)
    {
        if (x < 0.0)
            return 0.0;

        if (x > 1.0)
            return 1.0;

        return x;
    }

    void getLoopRange(double& startSample, double& endSample)
    {
        double maxSample = (double)data.numSamples - 2.0;

        if (maxSample < 0.0)
        {
            startSample = 0.0;
            endSample = 0.0;
            return;
        }

        startSample = clamp01(loopStart) * maxSample;
        endSample = clamp01(loopEnd) * maxSample;

        if (endSample < startSample)
        {
            double tmp = startSample;
            startSample = endSample;
            endSample = tmp;
        }

        if (endSample < startSample + 8.0)
            endSample = startSample + 8.0;

        if (endSample > maxSample)
            endSample = maxSample;

        if (startSample > endSample - 8.0)
            startSample = endSample - 8.0;

        if (startSample < 0.0)
            startSample = 0.0;
    }

    double findNearestZeroCrossing(double targetPos, double minPos, double maxPos)
    {
        if (data.numSamples < 2)
            return targetPos;

        int minIndex = (int)minPos;
        int maxIndex = (int)maxPos;

        if (minIndex < 0)
            minIndex = 0;

        if (maxIndex > data.numSamples - 2)
            maxIndex = data.numSamples - 2;

        int centre = (int)targetPos;
        if (centre < minIndex)
            centre = minIndex;

        if (centre > maxIndex)
            centre = maxIndex;

        int searchRadius = 128;
        int bestIndex = 0;
        int bestDistance = searchRadius + 1;
        bool foundCrossing = false;

        for (int offset = 0; offset <= searchRadius; offset++)
        {
            for (int c = 0; c < 2; c++)
            {
                int i = centre - offset;

                if (c == 1)
                    i = centre + offset;

                if (i < minIndex || i > maxIndex)
                    continue;

                float a = sample[0][i];
                float b = sample[0][i + 1];
                bool crossing = (a <= 0.0f && b > 0.0f) || (a >= 0.0f && b < 0.0f);

                if (crossing)
                {
                    int dist = i - centre;
                    if (dist < 0)
                        dist = centre - i;

                    if (dist < bestDistance)
                    {
                        bestDistance = dist;
                        bestIndex = i;
                        foundCrossing = true;
                    }
                }
            }

            if (foundCrossing)
                break;
        }

        if (foundCrossing == false)
            return targetPos;

        return (double)bestIndex;
    }

    double getFreezeStartPosition(double scrubNorm, double loopRangeStart, double regionLength, double thisGrainSize)
    {
        double maxStart = regionLength - thisGrainSize;
        double targetStart = loopRangeStart + (scrubNorm * maxStart);

        if (scrubMode == 1)
        {
            double minStart = loopRangeStart;
            double maxAllowedStart = loopRangeStart + maxStart;
            targetStart = findNearestZeroCrossing(targetStart, minStart, maxAllowedStart);
        }

        return targetStart;
    }
	
    struct VoiceData
    {
        double uptime = 0.0;   // read position
        double delta = 1.0;    // playback speed
        int noteNumber = 60;
        double activeScrub = 0.0;
        double pendingScrub = 0.0;
        double grainStart = 0.0;
        bool hasPendingScrub = false;

        void reset()
        {
            uptime = 0.0;
            activeScrub = 0.0;
            pendingScrub = 0.0;
            grainStart = 0.0;
            hasPendingScrub = false;
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
    double windowDenom = grainSize;

    if (freeze)
    {
        double sampleEnd = (double)data.numSamples - 2.0;
        if (sampleEnd < 8.0)
            return;

        double thisGrainSize = grainSize;
        if (thisGrainSize > sampleEnd)
            thisGrainSize = sampleEnd;

        if (thisGrainSize < 8.0)
            return;

        windowDenom = thisGrainSize;

        if (v.uptime <= 0.0)
            v.grainStart = getFreezeStartPosition(v.activeScrub, 0.0, sampleEnd, thisGrainSize);

        pos = v.grainStart + v.uptime;

        v.uptime += v.delta;

        if (v.uptime >= thisGrainSize)
        {
            v.uptime -= thisGrainSize;

            if (v.hasPendingScrub)
            {
                v.activeScrub = v.pendingScrub;
                v.hasPendingScrub = false;
            }

            v.grainStart = getFreezeStartPosition(v.activeScrub, 0.0, sampleEnd, thisGrainSize);
        }
    }
    else
    {
        pos = v.uptime;
        v.uptime += v.delta;

        if (loop)
        {
            double loopRangeStart = 0.0;
            double loopRangeEnd = 0.0;
            getLoopRange(loopRangeStart, loopRangeEnd);

            if (loopRangeEnd - loopRangeStart < 8.0)
                return;

            if (pos < loopRangeStart || pos >= loopRangeEnd)
                pos = loopRangeStart;

            if (v.uptime >= loopRangeEnd)
                v.uptime = loopRangeStart;
        }
        else if (pos >= (data.numSamples - 1))
        {
            return;
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
        double winPhase = v.uptime / windowDenom;
        double win = hann(winPhase);
        fd[ch] += (float)(((1.0 - frac) * s0 + frac * s1) * win);
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
            v.activeScrub = scrub;
            v.pendingScrub = scrub;

            if (loop && data.numSamples > 0)
            {
                double loopRangeStart = 0.0;
                double loopRangeEnd = 0.0;
                getLoopRange(loopRangeStart, loopRangeEnd);
                v.uptime = loopRangeStart;
            }

            double midiSemis = (double)(v.noteNumber - rootNote);
            double midiRatio = Math.pow(2.0, midiSemis / 12.0);
            double pitchMult = midiRatio * pitchRatio;

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
            double midiRatio = Math.pow(2.0, midiSemis / 12.0);
            double pitchMult = midiRatio * pitchRatio;

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
        // FreqRatio: direct playback multiplier.
        if (P == 0)
        {
            pitchRatio = v;
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

            for (auto& vd : voiceData)
            {
                vd.pendingScrub = scrub;
                vd.hasPendingScrub = true;

                if (!freeze)
                    vd.activeScrub = scrub;
            }
        }
        

        // 0..1 → ~20ms .. ~500ms (musical)
        // Grain size in milliseconds (direct input from UI)
        if (P == 4)
        {
            grainMs = v;   // v is already an exact millisecond value
            updateGrainSize();
        }

        if (P == 5)
        {
            loopStart = clamp01(v);
        }

        if (P == 6)
        {
            loopEnd = clamp01(v);
        }

        if (P == 7)
        {
            scrubMode = (v > 0.5) ? 1 : 0;
        }
    }
    
};
