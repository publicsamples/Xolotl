Content.makeFrontInterface(850, 580);

//const var rm = Engine.getGlobalRoutingManager();

include("UISTUFF.js");

//const eventdata = rm.getEventData(0, 0);
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);

//const cable1 = rm.getCable("mod1");
//const cable2 = rm.getCable("mod2");
//onst cable3 = rm.getCable("mod3");

const maps = Sampler.getSampleMapList();


const var BankA = Content.getComponent("BankA");

const Maps = [];


const BellKey = ["Bell_Belles", "Bell_More", "Bell_Src", "Keys_DCOPiano", "Keys_Darkly", "Keys_EM25_1", "Keys_EM25_2", "Keys_EM25_3", "Keys_EM25_4", "Keys_EP1", "Keys_EP2", "Keys_EP3", "Keys_Euro", "Keys_Odd", "Keys_Swoosh1", "Keys_Swoosh2", "Keys_Swoosh3", "Keys_pswp"];
const FX = ["FX_CrazyLFO", "FX_Devistate", "FX_Drama", "FX_FMRings", "FX_FeedFwd", "FX_Gooey", "FX_HiYearner", "FX_LickElectric", "FX_LoopG", "FX_MagicResin", "FX_S&H", "FX_Zap", "FX__Bypass", "FX_heartache", "FX_BeastMode", "FX_BrainSeq", "FX_BseqSmooth", "FX_Burd", "FX_SmearedToy", "FX_Swish", "FX_WowOhWow"];
const KitSeq = ["Kit_612_perc", "Kit_CS", "Kit_MP", "Kit_Sh2", "SEQ_Bumpkin130", "SEQ_SpaceRaider", "SEQ_TwistingMellow1", "SEQ_TwistingMellow2", "SEQ_revolve130", "SEQ_sale", "Seq_Lemon90", "Seq_consider"];
const Lead = ["Lead_2ndFinger", "Lead_Astonish", "Lead_Astonished", "Lead_Bargain", "Lead_Basic", "Lead_Brew", "Lead_Cream", "Lead_CrumbFlute", "Lead_Crunch", "Lead_Crunchy", "Lead_CupCake", "Lead_Curious", "Lead_DF1", "Lead_Day3", "Lead_Drink", "Lead_Egg", "Lead_FakeSync", "Lead_Fingers", "Lead_Grizzle", "Lead_K30L", "Lead_K_Legs", "Lead_Log", "Lead_Lozange", "Lead_Messin", "Lead_PseudoSync", "Lead_RavST", "Lead_Rodge", "Lead_SadRing", "Lead_Sayer", "Lead_SaysThings", "Lead_Scream", "Lead_Screamer", "Lead_ShRes", "Lead_Simple", "Lead_SimpleJx", "Lead_SlwRing1", "Lead_SlwRing2", "Lead_SlwRing3", "Lead_TSync", "Lead_Tinkle", "Lead_funny", "Lead_harsh", "Lead_k30l2", "Lead_mth", "Lead_rude", "Lead_sawd", "Lead_stix"];
const Misc = ["Misc_EM25_1", "Misc_EM25_2", "Misc_EM25_3", "Misc_Gdad_1", "Misc_Gdad_2", "Misc_Gdad_3", "Misc_Gdad_4", "Misc_Gdad_5", "Misc_Meta_1", "Misc_Meta_2", "Misc_Meta_3", "Misc_Meta_4", "Misc_Meta_5", "Misc_SplGit", "Misc_Spook", "Misc_Toes", "Misc_Vibe", "Misc_WBrass", "Misc_Wet", "Pluck_Gater", "Pluck_PluckSH", "Bass_BooBass", "Bass_Bz", "Bass_Double", "Bass_Gooey", "Bass_HardBass", "Bass_HellCat", "Bass_Lilbass", "Bass_RM", "Bass_Round", "Bass_ShakeyBass", "Bass_Shrp", "Bass_Slap", "Bass_eBass", "Bass_hard", "Bass_nsty1", "Bass_nsty2"];
const Pad = ["Pad_BigElectric", "Pad_Bumpy", "Pad_Busy", "Pad_CsShock", "Pad_DF2", "Pad_DS", "Pad_Gravel", "Pad_GreatST", "Pad_Lfade", "Pad_Lingo", "Pad_OChord", "Pad_PulseString", "Pad_RLD", "Pad_Rouse", "Pad_Rust", "Pad_Scratchy", "Pad_Scrd", "Pad_SlowOne", "Pad_Special", "Pad_Swish", "Pad_Tortoise", "Pad_Trouble", "Pad_XpSea", "Pad_simr", " Strings_Classy", "Strings_EM25_1", "Strings_EM25_2", "Strings_EM25_3", "Strings_Z1_1", "Strings_Z1_2"];
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

inline function onCategoriesControl(component, value)
{

	BankA.set("items", [].join("\n")); 
	BankA.set("items", Maps[value-1].join("\n"));
//	BankA.setValue(1);
	

};

Content.getComponent("Categories").setControlCallback(onCategoriesControl);


inline function onWAVELABEL1Control(component, value)
{
slot.loadFile("{XYZ::SampleMap}" + WAVELABEL1.get("text"));
};

Content.getComponent("WAVELABEL1").setControlCallback(onWAVELABEL1Control);



///slot.loadFile("{XYZ::SampleMap}" + (WAVELABEL1.get("text")[value-1]));

inline function onBankAControl(component, value)
{
	WAVELABEL1.set("text",BankA.get("items").split("\n")[value-1]);
	
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
//	slot.loadFile("{XYZ::SampleMap}" + (maps[value-1]));
};

Content.getComponent("BankA").setControlCallback(onBankAControl);


Settings.setVoiceMultiplier(8);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");





const var SampleLoad = [Content.getComponent("SAMPLE"),
                        Content.getComponent("WAVE6"),
                        Content.getComponent("Categories"),
                        Content.getComponent("BankA")];


const var HARMONIC = Synth.getEffect("HARMONIC");
const var OscWave = Content.getComponent("OscWave");
const var OSC = Content.getComponent("OSC");
const var MULTI = Content.getComponent("MULTI");
const var USER = Content.getComponent("USER");


const var UserParam = Content.getComponent("UserParam");



inline function onOscWaveControl(component, value)
{

	if(value == 1)
	{	 
	    HARMONIC.setAttribute(HARMONIC.VoiceMode, 1);
	    OSC.showControl(1);
	    MULTI.showControl(0);
	     USER.showControl(0);
	   
	}
	
		if(value == 2)
	{
		HARMONIC.setAttribute(HARMONIC.VoiceMode, 3);
		    OSC.showControl(0);
	           MULTI.showControl(0);
	           USER.showControl(1);

	}
	
			if(value == 3)
		{
			HARMONIC.setAttribute(HARMONIC.VoiceMode, 2);
			OSC.showControl(0);
			MULTI.showControl(1);
			USER.showControl(0);	     
	
		}
		
																
};

Content.getComponent("OscWave").setControlCallback(onOscWaveControl);




const var LFO1 = Synth.getModulator("LFO1");
const var LFO2 = Synth.getModulator("LFO2");
const var LFO3 = Synth.getModulator("LFO3");


inline function onComboBox1Control(component, value)
{
LFO1.setAttribute(LFO1.Modifiers, value-1);
};

Content.getComponent("ComboBox1").setControlCallback(onComboBox1Control);


inline function onComboBox2Control(component, value)
{
LFO2.setAttribute(LFO2.Modifiers, value-1);
};

Content.getComponent("ComboBox2").setControlCallback(onComboBox2Control);


inline function onComboBox3Control(component, value)
{
LFO3.setAttribute(LFO3.Modifiers, value-1);
};

Content.getComponent("ComboBox3").setControlCallback(onComboBox3Control);


inline function onOscWave1Control(component, value)
{

Engine.allNotesOff();

 HARMONIC.setAttribute(HARMONIC.OscType, value);
};

Content.getComponent("OscWave1").setControlCallback(onOscWave1Control);

const var Stages = Content.getComponent("Stages");


inline function onStagesControl(component, value)
{

	
	
		if(value == 1)
		{	 
		Engine.allNotesOff();
			HARMONIC.setAttribute(HARMONIC.Stages, 4);
			}
		if(value == 2)
				{	 
				Engine.allNotesOff();
			HARMONIC.setAttribute(HARMONIC.Stages, 8);
					}	
		if(value == 3)
						{	
						Engine.allNotesOff(); 
					HARMONIC.setAttribute(HARMONIC.Stages, 16);
							}				
			if(value == 4)
							{	 
							Engine.allNotesOff();
						HARMONIC.setAttribute(HARMONIC.Stages, 24);
								}	
	if(value == 5)
							{	
							Engine.allNotesOff(); 
						HARMONIC.setAttribute(HARMONIC.Stages, 32);
								}								
};

Content.getComponent("Stages").setControlCallback(onStagesControl);

const var ModSp1 = Content.getComponent("ModSp1");
const var ModSp2 = Content.getComponent("ModSp2");
const var ModSp3 = Content.getComponent("ModSp3");
const var ModSp4 = Content.getComponent("ModSp4");

inline function onModShapeControl(component, value)
{
	if(value == 1)
		{
	HARMONIC.setAttribute(HARMONIC.FxSinSh, 1);
	ModSp1.showControl(1);
	ModSp2.showControl(0);
	ModSp3.showControl(0);
	ModSp4.showControl(0);
    	}
	if(value == 2)
		{
	HARMONIC.setAttribute(HARMONIC.FxSinSh, 2);
	ModSp1.showControl(1);
	ModSp2.showControl(0);
	ModSp3.showControl(0);
	ModSp4.showControl(0);
    	}
	if(value == 3)
		{
	HARMONIC.setAttribute(HARMONIC.FxSinSh, 3);
	ModSp1.showControl(1);
	ModSp2.showControl(0);
	ModSp3.showControl(0);
	ModSp4.showControl(0);
    	}
	if(value == 4)
		{
	HARMONIC.setAttribute(HARMONIC.FxSinSh, 4);
	ModSp1.showControl(0);
	ModSp2.showControl(1);
	ModSp3.showControl(1);
	ModSp4.showControl(1);
    	}

};

Content.getComponent("ModShape").setControlCallback(onModShapeControl);


//USer Wave

const var HARMONICWave = Synth.getAudioSampleProcessor("HARMONIC");

inline function onWaveLoadControl(component, value)
{
	

	if (value)
			{
			FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
		{

	slot1.loadFile( (f.toString(File.FullPath)));
	});	
	
if(value == 1)
	
		{
	Engine.allNotesOff();
	
}

}
};


Content.getComponent("WaveLoad").setControlCallback(onWaveLoadControl);


const var SilentSynth1 = Synth.getChildSynth("Silent Synth1");
const var UserB3 = Content.getComponent("UserB3");

const var SynthesiserGroup1 = Synth.getChildSynth("Synthesiser Group1");
const var Knob5 = Content.getComponent("Knob5");

// PRESETS ///////////////////////
const var pmenu = Content.getComponent("pmenu");
var menuItems = [];

const var x = Engine.getUserPresetList(); 
for (i in x)
	menuItems.insert(-1, i);

menuItems = menuItems.join("\n");
pmenu.set("items", menuItems);

inline function onpmenuControl(component, value)
{
	Engine.loadUserPreset(pmenu.getItemText() + ".preset");
};

Content.getComponent("pmenu").setControlCallback(onpmenuControl);




function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 