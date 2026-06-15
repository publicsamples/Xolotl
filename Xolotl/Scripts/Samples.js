Synth.deferCallbacks(true);

//Single Sample

const var AudioList = Engine.loadAudioFilesIntoPool();

const var SampleA = Content.getComponent("SampleA");
const var SampleA1 = Content.getComponent("SampleA1");
const var SampleA2 = Content.getComponent("SampleA2");
const var SampleA3 = Content.getComponent("SampleA3");
const var SampleA4 = Content.getComponent("SampleA4");
const var SampleA5 = Content.getComponent("SampleA5");
const var SampleA6 = Content.getComponent("SampleA6");
const var SampleA7 = Content.getComponent("SampleA7");
const var SampleA8 = Content.getComponent("SampleA8");
const var SampleA9 = Content.getComponent("SampleA9");
const var SampleA10 = Content.getComponent("SampleA10");
const var SampleA11 = Content.getComponent("SampleA11");
const var SampleA12 = Content.getComponent("SampleA12");
const var SampleA13 = Content.getComponent("SampleA13");
const var SampleA14 = Content.getComponent("SampleA14");
const var SampleA15 = Content.getComponent("SampleA15");


const var SampleBank = Content.getComponent("SampleBank");

const var harm = Synth.getAudioSampleProcessor("HARMONIC");

const var foldersV1 = [];        // Top-level Genre foldersV1
const var instrumentsV1 = {};    // Maps Genre to Instruments
const var samplesV1 = {};  


const slot = harm.getAudioFile(0);

const slot1 = harm.getAudioFile(1);
const slot2 = harm.getAudioFile(2);
const slot3 = harm.getAudioFile(3);
const slot4 = harm.getAudioFile(4);
const slot5 = harm.getAudioFile(5);
const slot6 = harm.getAudioFile(6);
const slot7 = harm.getAudioFile(7);
const slot8 = harm.getAudioFile(8);
const slot9 = harm.getAudioFile(9);
const slot10 = harm.getAudioFile(10);
const slot11 = harm.getAudioFile(11);
const slot12 = harm.getAudioFile(12);
const slot13 = harm.getAudioFile(13);
const slot14 = harm.getAudioFile(14);
const slot15 = harm.getAudioFile(15);
const slot16 = harm.getAudioFile(16);

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

inline function onSampleBankControl(component, value)
{
  if (value >= 0) {
        // Get the selected Genre
        local selectedGenre = foldersV1[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV1 in the selected Genre
        if (instrumentsV1[selectedGenre]) {
            SampleA.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA1.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA2.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA3.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA4.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA5.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA6.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA7.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA8.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA9.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA10.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA11.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA12.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA13.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA14.set("items", instrumentsV1[selectedGenre].join("\n"));
			SampleA15.set("items", instrumentsV1[selectedGenre].join("\n"));

     
        } else {
            SampleA.set("items", "no file");
            SampleA1.set("items", "no file");
            SampleA2.set("items", "no file");
            SampleA3.set("items", "no file");
            SampleA4.set("items", "no file");
			SampleA5.set("items", "no file");
			SampleA6.set("items", "no file");
			SampleA7.set("items", "no file");
			SampleA8.set("items", "no file");
			SampleA9.set("items", "no file");
			SampleA10.set("items", "no file");
			SampleA11.set("items", "no file");
			SampleA12.set("items", "no file");
			SampleA13.set("items", "no file");
			SampleA14.set("items", "no file");
			SampleA15.set("items", "no file");
        }

        // Clear SampleV1 as no Instrument is selected yet

        
     //   FirstCB.setValue(value);
		SampleA.setValue(value);
	
         
    }
}

Content.getComponent("SampleBank").setControlCallback(onSampleBankControl);

inline function loadIncrementalSamples(startIndex)

{

   slot1.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA.getItemText());
        slot2.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA1.getItemText());
        slot3.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA2.getItemText());
        slot4.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA3.getItemText());
        slot5.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA4.getItemText());
        slot6.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA5.getItemText());
        slot7.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA6.getItemText());
        slot8.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA7.getItemText());
        slot9.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA8.getItemText());
        slot10.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA9.getItemText());
        slot11.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA10.getItemText());
        slot12.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA11.getItemText());
        slot13.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA12.getItemText());
        slot14.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA13.getItemText());
        slot15.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA14.getItemText());
        slot16.loadFile("{PROJECT_FOLDER}" + SampleBank.getItemText()  + "/" + SampleA15.getItemText());
        

}


inline function onSampleAControl(component, value)




{
	
	SampleA1.setValue(value +1);
		SampleA2.setValue(value +2);
		SampleA3.setValue(value +3);
		SampleA4.setValue(value +4);
		SampleA5.setValue(value +5);
		SampleA6.setValue(value +6);
		SampleA7.setValue(value +7);
		SampleA8.setValue(value +8);
		SampleA9.setValue(value +9);
		SampleA10.setValue(value +10);
		SampleA11.setValue(value +11);
		SampleA12.setValue(value +12);
		SampleA13.setValue(value +13);
		SampleA14.setValue(value +14);
		SampleA15.setValue(value +15);
		
if (value >= 0) {
	

		local selectedSample = SampleA.get("items").split("\n")[value - 1];

       // Construct the full path to the sample
       local selectedGenre = SampleBank.getItemText();
      // local selectedInstrument = SecondCB.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedSample;

	
	SynthesiserGroup1.setBypassed(false);
	reg voc1 = value-1;
	
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		SynthesiserGroup1.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{
	
	
		SynthesiserGroup1.setBypassed(false);

 		  loadIncrementalSamples(value - 1);
    
    
    }, this);

	}, ScriptnodeSynthesiser1);
}
}

Content.getComponent("SampleA").setControlCallback(onSampleAControl);


//Multi-sample

const maps = Sampler.getSampleMapList();


const var BankA = Content.getComponent("BankA");

const Maps = [];


const BellKey = ["Bell_Belles", "Bell_More", "Bell_Src", "Keys_DCOPiano", "Keys_Darkly", "Keys_EM25_1", "Keys_EM25_2", "Keys_EM25_3", "Keys_EM25_4", "Keys_Euro", "Keys_Odd", "Keys_Swoosh1", "Keys_Swoosh2", "Keys_Swoosh3"];
const FX = ["FX_CrazyLFO", "FX_Devistate", "FX_Drama", "FX_FMRings", "FX_FeedFwd", "FX_Gooey", "FX_HiYearner", "FX_LickElectric", "FX_LoopG", "FX_MagicResin", "FX_S&H", "FX_Zap", "FX_BeastMode", "FX_BrainSeq", "FX_BseqSmooth", "FX_Burd", "FX_SmearedToy", "FX_Swish", "FX_WowOhWow"];
const Lead = ["Lead_Astonish", "Lead_Bargain", "Lead_Basic",  "Lead_Cream", "Lead_Crunch", "Lead_Crunchy", "Lead_CupCake", "Lead_DF1", "Lead_Day3", "Lead_Drink", "Lead_Egg", "Lead_FakeSync", "Lead_Fingers",  "Lead_K30L", "Lead_K_Legs", "Lead_Log", "Lead_Lozange", "Lead_Messin", "Lead_PseudoSync", "Lead_RavST", "Lead_Rodge", "Lead_SadRing", "Lead_Sayer",  "Lead_Scream", "Lead_ShRes", "Lead_Simple", "Lead_SimpleJx", "Lead_SlwRing1", "Lead_SlwRing2", "Lead_SlwRing3", "Lead_TSync", "Lead_Tinkle", "Lead_funny", "Lead_harsh", "Lead_mth", "Lead_rude", "Lead_stix"];
const Misc = ["Misc_EM25_1", "Misc_EM25_2", "Misc_EM25_3", "Misc_Gdad_1", "Misc_Gdad_2", "Misc_Gdad_3", "Misc_Gdad_4", "Misc_Gdad_5", "Misc_Meta_1", "Misc_Meta_2", "Misc_Meta_3", "Misc_Meta_4", "Misc_Meta_5", "Misc_SplGit", "Misc_Spook", "Misc_Toes", "Misc_Vibe", "Misc_WBrass", "Misc_Wet", "Pluck_Gater", "Pluck_PluckSH", "Bass_BooBass", "Bass_Bz", "Bass_Double", "Bass_Gooey", "Bass_HardBass", "Bass_HellCat", "Bass_Lilbass", "Bass_RM", "Bass_Round", "Bass_Shrp", "Bass_Slap", "Bass_eBass", "Bass_hard"];
const Pad = ["Pad_BigElectric", "Pad_Bumpy", "Pad_Busy", "Pad_CsShock", "Pad_DF2", "Pad_DS", "Pad_Gravel", "Pad_GreatST", "Pad_Lfade", "Pad_Lingo", "Pad_OChord", "Pad_PulseString", "Pad_RLD", "Pad_Rouse", "Pad_Rust", "Pad_Scratchy", "Pad_Scrd", "Pad_SlowOne", "Pad_Special", "Pad_Swish", "Pad_Tortoise", "Pad_Trouble", "Pad_XpSea", "Pad_simr", "Strings_EM25_1", "Strings_EM25_2", "Strings_EM25_3", "Strings_Z1_1", "Strings_Z1_2"];




Maps.push(BellKey);
Maps.push(FX);
Maps.push(Lead);
Maps.push(Misc);
Maps.push(Pad);

const SMAPS = ["Bells & Keys", "FX", "Leads", "Misc", "Pads"];


// BANK A
//BankA.set("items", "");
//BankA.set("items", maps.join("\n"));
const var WAVELABEL1 = Content.getComponent("WAVELABEL1");


const var Categories = Content.getComponent("Categories");

Categories.set("items", SMAPS.join("\n"));

inline function onCategoriesControl(component, value)
{

	BankA.set("items", [].join("\n")); 
	BankA.set("items", Maps[value-1].join("\n"));
//	BankA.setValue(1);
	

};

Content.getComponent("Categories").setControlCallback(onCategoriesControl);



///slot.loadFile("{XYZ::SampleMap}" + (WAVELABEL1.get("text")[value-1]));

inline function onBankAControl(component, value)
{
	WAVELABEL1.set("text", BankA.get("items").split("\n")[value-1]);
	
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
//	slot.loadFile("{XYZ::SampleMap}" + (maps[value-1]));
};

Content.getComponent("BankA").setControlCallback(onBankAControl);

inline function onWAVELABEL1Control(component, value)
{
slot.loadFile("{XYZ::SampleMap}" + WAVELABEL1.get("text"));
};

Content.getComponent("WAVELABEL1").setControlCallback(onWAVELABEL1Control);



//User Wave

const var HARMONICWave = Synth.getAudioSampleProcessor("HARMONIC");

inline function onWaveLoadControl(component, value)
{
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