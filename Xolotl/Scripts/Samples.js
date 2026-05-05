Synth.deferCallbacks(true);

// Global preset-restore lock shared by active scripts.
var g_presetRestoreBusy = false;

inline function sortAudioFilesListV1() {
	
	Synth.deferCallbacks(true);
///	for (file in samplesArray) {
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];
        
     
	
	

     
       if (foldersV1.indexOf(genreFolder) == -1) {
           foldersV1.push(genreFolder);
           instrumentsV1[genreFolder] = []; 
        }

       
        if (instrumentsV1[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV1[genreFolder].push(instrumentFolder);
            samplesV1[instrumentFolder] = []; 
        }


       samplesV1[instrumentFolder].push(sampleFile);
  
  
    }


   SampleBank.set("items", foldersV1.join("\n"));
 //  SampleA.set("items", foldersV1.join("\n"));

}



// Run the sorting function
sortAudioFilesListV1();

var g_sampleLoadToken = 0;


inline function onSampleBankControl(component, value)
{
  if (value <= 0 || value > foldersV1.length)
      return;

        // Get the selected Genre
        local selectedGenre = foldersV1[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV1 in the selected Genre
        if (instrumentsV1[selectedGenre]) {
            SampleA.set("items", instrumentsV1[selectedGenre].join("\n"));

     
        } else {
            SampleA.set("items", "no file");



        }

        // Clear SampleV1 as no Instrument is selected yet

        
     //   FirstCB.setValue(value);
		// Do not force SampleA here. During preset restore this can overwrite
		// the preset's SampleA value and trigger a load with half-restored state.
         
}

Content.getComponent("SampleBank").setControlCallback(onSampleBankControl);



inline function onSampleAControl(component, value)
{
	if (g_presetRestoreBusy)
		return;

	if (value <= 0)
		return;

		local sampleItems = SampleA.get("items").split("\n");

		if (value > sampleItems.length)
			return;

		local selectedSample = sampleItems[value - 1];

		if (selectedSample.length == 0 || selectedSample == "no file")
			return;

       // Construct the full path to the sample
       local selectedGenre = SampleBank.getItemText();

       if (selectedGenre.length == 0)
           return;

       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedSample;
       g_sampleLoadToken = g_sampleLoadToken + 1;
       local loadToken = g_sampleLoadToken;

	
	SynthesiserGroup1.setBypassed(false);
	reg voc1 = value-1;
	
	Content.callAfterDelay(300, function [loadToken, fullPath]()
	{
		if (loadToken != g_sampleLoadToken)
			return;

		Engine.allNotesOff();
	
		SynthesiserGroup1.setBypassed(true);
		
		Content.callAfterDelay(300, function [loadToken, fullPath]()
		{
			if (loadToken != g_sampleLoadToken)
				return;
	
	
		SynthesiserGroup1.setBypassed(false);

   
        // Load the sample using the validated path from callback time.
        slot1.loadFile(fullPath);
      //  Console.print("Sample loaded successfully!");
    
    
    }, this);

	});
}

Content.getComponent("SampleA").setControlCallback(onSampleAControl);


//const eventdata = rm.getEventData(0, 0);

const slot1 = harm.getAudioFile(1);

//const cable1 = rm.getCable("mod1");
//const cable2 = rm.getCable("mod2");
//onst cable3 = rm.getCable("mod3");

const maps = Sampler.getSampleMapList();


const var BankA = Content.getComponent("BankA");

const Maps = [];


const BellKey = ["Bell_Belles", "Bell_More", "Bell_Src", "Keys_DCOPiano", "Keys_Darkly", "Keys_EM25_1", "Keys_EM25_2", "Keys_EM25_3", "Keys_EM25_4", "Keys_EP1", "Keys_EP2", "Keys_EP3", "Keys_Euro", "Keys_Odd", "Keys_Swoosh1", "Keys_Swoosh2", "Keys_Swoosh3", "Keys_pswp"];
const FX = ["FX_CrazyLFO", "FX_Devistate", "FX_Drama", "FX_FMRings", "FX_FeedFwd", "FX_Gooey", "FX_HiYearner", "FX_LickElectric", "FX_LoopG", "FX_MagicResin", "FX_S&H", "FX_Zap", "FX_Bypass", "FX_heartache", "FX_BeastMode", "FX_BrainSeq", "FX_BseqSmooth", "FX_Burd", "FX_SmearedToy", "FX_Swish", "FX_WowOhWow"];
const KitSeq = ["Kit_612_perc", "Kit_CS", "Kit_MP", "Kit_SH2", "SEQ_Bumpkin130", "SEQ_SpaceRaider", "SEQ_TwistingMellow1", "SEQ_TwistingMellow2", "SEQ_revolve130", "SEQ_sale", "Seq_Lemon90", "Seq_consider"];
const Lead = ["Lead_2ndFinger", "Lead_Astonish", "Lead_Astonished", "Lead_Bargain", "Lead_Basic", "Lead_Brew", "Lead_Cream", "Lead_CrumbFlute", "Lead_Crunch", "Lead_Crunchy", "Lead_CupCake", "Lead_Curious", "Lead_DF1", "Lead_Day3", "Lead_Drink", "Lead_Egg", "Lead_FakeSync", "Lead_Fingers", "Lead_Grizzle", "Lead_K30L", "Lead_K_Legs", "Lead_Log", "Lead_Lozange", "Lead_Messin", "Lead_PseudoSync", "Lead_RavST", "Lead_Rodge", "Lead_SadRing", "Lead_Sayer", "Lead_SaysThings", "Lead_Scream", "Lead_Screamer", "Lead_ShRes", "Lead_Simple", "Lead_SimpleJx", "Lead_SlwRing1", "Lead_SlwRing2", "Lead_SlwRing3", "Lead_TSync", "Lead_Tinkle", "Lead_funny", "Lead_harsh", "Lead_k30l2", "Lead_mth", "Lead_rude", "Lead_sawd", "Lead_stix"];
const Misc = ["Misc_EM25_1", "Misc_EM25_2", "Misc_EM25_3", "Misc_Gdad_1", "Misc_Gdad_2", "Misc_Gdad_3", "Misc_Gdad_4", "Misc_Gdad_5", "Misc_Meta_1", "Misc_Meta_2", "Misc_Meta_3", "Misc_Meta_4", "Misc_Meta_5", "Misc_SplGit", "Misc_Spook", "Misc_Toes", "Misc_Vibe", "Misc_WBrass", "Misc_Wet", "Pluck_Gater", "Pluck_PluckSH", "Bass_BooBass", "Bass_Bz", "Bass_Double", "Bass_Gooey", "Bass_HardBass", "Bass_HellCat", "Bass_Lilbass", "Bass_RM", "Bass_Round", "Bass_ShakeyBass", "Bass_Shrp", "Bass_Slap", "Bass_eBass", "Bass_hard", "Bass_nsty1", "Bass_nsty2"];
const Pad = ["Pad_BigElectric", "Pad_Bumpy", "Pad_Busy", "Pad_CsShock", "Pad_DF2", "Pad_DS", "Pad_Gravel", "Pad_GreatST", "Pad_Lfade", "Pad_Lingo", "Pad_OChord", "Pad_PulseString", "Pad_RLD", "Pad_Rouse", "Pad_Rust", "Pad_Scratchy", "Pad_Scrd", "Pad_SlowOne", "Pad_Special", "Pad_Swish", "Pad_Tortoise", "Pad_Trouble", "Pad_XpSea", "Pad_simr", "Strings_Classy", "Strings_EM25_1", "Strings_EM25_2", "Strings_EM25_3", "Strings_Z1_1", "Strings_Z1_2"];
const Waves = ["Wave_MP4xSaw1", "Wave_MP4xSaw2", "Wave_MPSawA1", "Wave_MPSawA2", "Wave_MPSawA3", "Wave_MPSawA4", "Wave_MPSawB1", "Wave_MPSawB2", "Wave_MPSawB3", "Wave_MPSqr_1", "Wave_MPSqr_2", "Wave_MPSqr_3", "Wave_MPSqr_4", "Wave_MPSqr_5", "Wave_MPTri", "Wave_Noise", "Wave_Noise1", "Wave_Noise2", "Wave_Noise3", "Wave_Noise4", "Wave_Pulse1", "Wave_Pulse2", "Wave_Pulse3", "Wave_Saw", "Wave_Sine"];



Maps.push(BellKey);
Maps.push(FX);
Maps.push(KitSeq);
Maps.push(Lead);
Maps.push(Misc);
Maps.push(Pad);
Maps.push(Waves);

const SMAPS = ["Bells & Keys", "FX","Kits & Seq", "Leads", "Misc", "Pads", "Basic Waves"];


// BANK A
//BankA.set("items", "");
//BankA.set("items", maps.join("\n"));
const var WAVELABEL1 = Content.getComponent("WAVELABEL1");


const var Categories = Content.getComponent("Categories");

Categories.set("items", SMAPS.join("\n"));

var g_pendingSampleMapId = "";
var g_isSampleMapLoadScheduled = false;
var g_lastLoadedSampleMapId = "";
var g_sampleMapLoadToken = 0;

inline function isValidSampleMapId(id)
{
	return id.length > 0 && maps.indexOf(id) != -1;
}

inline function requestSampleMapLoad(mapId)
{
	if (g_presetRestoreBusy)
		return;

	if (!isValidSampleMapId(mapId))
		return;

	g_pendingSampleMapId = mapId;
	g_sampleMapLoadToken = g_sampleMapLoadToken + 1;
	local loadToken = g_sampleMapLoadToken;

	if (g_isSampleMapLoadScheduled)
		return;

	g_isSampleMapLoadScheduled = true;

	Content.callAfterDelay(500, function [loadToken]()
	{
		if (loadToken != g_sampleMapLoadToken)
		{
			g_isSampleMapLoadScheduled = false;
			requestSampleMapLoad(g_pendingSampleMapId);
			return;
		}

		var id = g_pendingSampleMapId;
		g_pendingSampleMapId = "";
		g_isSampleMapLoadScheduled = false;

		if (!isValidSampleMapId(id))
			return;

		if (id == g_lastLoadedSampleMapId)
			return;

		g_lastLoadedSampleMapId = id;
		slot.loadFile("{XYZ::SampleMap}" + id);
	}, WAVELABEL1);
}

inline function onCategoriesControl(component, value)
{
	if (value <= 0 || value > Maps.length)
		return;

	BankA.set("items", [].join("\n")); 
	BankA.set("items", Maps[value-1].join("\n"));
//	BankA.setValue(1);
	

};

Content.getComponent("Categories").setControlCallback(onCategoriesControl);


inline function onWAVELABEL1Control(component, value)
{
	// Diagnostic guard: preset restore can fire this label callback in bursty
	// order; avoid sample-map loads from label state and load only via BankA.
	return;
};

Content.getComponent("WAVELABEL1").setControlCallback(onWAVELABEL1Control);



///slot.loadFile("{XYZ::SampleMap}" + (WAVELABEL1.get("text")[value-1]));

inline function onBankAControl(component, value)
{
	if (g_presetRestoreBusy)
		return;

	if (value <= 0)
		return;

	local bankItems = BankA.get("items").split("\n");

	if (value > bankItems.length)
		return;

	local mapId = bankItems[value-1];

	if (!isValidSampleMapId(mapId))
		return;

	WAVELABEL1.set("text", mapId);
	
	requestSampleMapLoad(mapId);
//	slot.loadFile("{XYZ::SampleMap}" + (maps[value-1]));
};

Content.getComponent("BankA").setControlCallback(onBankAControl);

inline function reconcileSampleStateAfterPreset()
{
	local catValue = Categories.getValue();
	if (catValue > 0 && catValue <= Maps.length)
		onCategoriesControl(Categories, catValue);

	local bankValue = BankA.getValue();
	if (bankValue > 0)
		onBankAControl(BankA, bankValue);

	local sampleValue = SampleA.getValue();
	if (sampleValue > 0)
		onSampleAControl(SampleA, sampleValue);
}


//USer Wave

const var HARMONICWave = Synth.getAudioSampleProcessor("HARMONIC");

inline function onWaveLoadControl(component, value)
{
	if (g_presetRestoreBusy)
		return;

	Engine.allNotesOff();

	SynthesiserGroup1.setBypassed(value);

	if (value)
			{
			FileSystem.browse (FileSystem.Music, false, "*.wav,*.aif ", function (f) 
		{

	slot1.loadFile( (f.toString(File.FullPath)));
	});	
	


}
};


Content.getComponent("WaveLoad").setControlCallback(onWaveLoadControl);
