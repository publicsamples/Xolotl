Content.makeFrontInterface(850, 580);

const var rm = Engine.getGlobalRoutingManager();

include("UISTUFF.js");

const eventdata = rm.getEventData(0, 0);
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);

const cable1 = rm.getCable("mod1");
const cable2 = rm.getCable("mod2");
const cable3 = rm.getCable("mod3");

const maps = Sampler.getSampleMapList();

const var User1 = Content.getComponent("User1");

User1.setRange(0.2, 1, 0.2);

const var BankA = Content.getComponent("BankA");

var Bass = ["Bass_BooBass", "Bass_Bz", "Bass_Double", "Bass_Gooey", "Bass_HardBass", "Bass_HellCat", "Bass_Lilbass", "Bass_RM", "Bass_Round", "Bass_ShakeyBass", "Bass_Shrp", "Bass_Slap", "Bass_eBass", "Bass_hard", "Bass_nsty1", "Bass_nsty2"];
var BellKey = ["Bell_Belles", "Bell_More", "Bell_Src", "Keys_DCOPiano", "Keys_Darkly", "Keys_EM25_1", "Keys_EM25_2", "Keys_EM25_3", "Keys_EM25_4", "Keys_EP1", "Keys_EP2", "Keys_EP3", "Keys_Euro", "Keys_Odd", "Keys_Swoosh1", "Keys_Swoosh2", "Keys_Swoosh3", "Keys_pswp"];
var FX = ["FX_CrazyLFO", "FX_Devistate", "FX_Drama", "FX_FMRings", "FX_FeedFwd", "FX_Gooey", "FX_HiYearner", "FX_LickElectric", "FX_LoopG", "FX_MagicResin", "FX_S&H", "FX_Zap", "FX__Bypass", "FX_heartache", "Fx_BeastMode", "Fx_BrainSeq", "Fx_BseqSmooth", "Fx_Burd", "Fx_SmearedToy", "Fx_Swish", "Fx_WowOhWow"];
var KitSeq = ["Kit_612_perc", "Kit_CS", "Kit_MP", "Kit_Sh2", "SEQ_Bumpkin130", "SEQ_SpaceRaider", "SEQ_TwistingMellow1", "SEQ_TwistingMellow2", "SEQ_revolve130", "SEQ_sale", "Seq_Lemon90", "Seq_consider"];
var Lead = ["Lead_2ndFinger", "Lead_Astonish", "Lead_Astonished", "Lead_Bargain", "Lead_Basic", "Lead_Brew", "Lead_Cream", "Lead_CrumbFlute", "Lead_Crunch", "Lead_Crunchy", "Lead_CupCake", "Lead_Curious", "Lead_DF1", "Lead_Day3", "Lead_Drink", "Lead_Egg", "Lead_FakeSync", "Lead_Fingers", "Lead_Grizzle", "Lead_K30L", "Lead_K_Legs", "Lead_Log", "Lead_Lozange", "Lead_Messin", "Lead_PseudoSync", "Lead_RavST", "Lead_Rodge", "Lead_SadRing", "Lead_Sayer", "Lead_SaysThings", "Lead_Scream", "Lead_Screamer", "Lead_ShRes", "Lead_Simple", "Lead_SimpleJx", "Lead_SlwRing1", "Lead_SlwRing2", "Lead_SlwRing3", "Lead_TSync", "Lead_Tinkle", "Lead_funny", "Lead_harsh", "Lead_k30l2", "Lead_mth", "Lead_rude", "Lead_sawd", "Lead_stix"];
var Misc = ["Misc_EM25_1", "Misc_EM25_2", "Misc_EM25_3", "Misc_Gdad_1", "Misc_Gdad_2", "Misc_Gdad_3", "Misc_Gdad_4", "Misc_Gdad_5", "Misc_Meta_1", "Misc_Meta_2", "Misc_Meta_3", "Misc_Meta_4", "Misc_Meta_5", "Misc_SplGit", "Misc_Spook", "Misc_Toes", "Misc_Vibe", "Misc_WBrass", "Misc_Wet", "Pluck_Gater", "Pluck_PluckSH"];
var Pad = ["Pad_BigElectric", "Pad_Bumpy", "Pad_Busy", "Pad_CsShock", "Pad_DF2", "Pad_DS", "Pad_Gravel", "Pad_GreatST", "Pad_Lfade", "Pad_Lingo", "Pad_OChord", "Pad_PulseString", "Pad_RLD", "Pad_Rouse", "Pad_Rust", "Pad_Scratchy", "Pad_Scrd", "Pad_SlowOne", "Pad_Special", "Pad_Swish", "Pad_Tortoise", "Pad_Trouble", "Pad_XpSea", "Pad_simr", " Strings_Classy", "Strings_EM25_1", "Strings_EM25_2", "Strings_EM25_3", "Strings_Z1_1", "Strings_Z1_2"];
var Waves = ["Wave_HT_01", "Wave_HT_02", "Wave_HT_03", "Wave_HT_04", "Wave_HT_05", "Wave_HT_06", "Wave_HT_07", "Wave_HT_08", "Wave_HT_09", "Wave_HT_10", "Wave_HT_11", "Wave_HT_12", "Wave_HT_13", "Wave_HT_14", "Wave_HT_15", "Wave_HT_16", "Wave_HT_17", "Wave_HT_18", "Wave_HT_19", "Wave_HT_20", "Wave_HT_21", "Wave_HT_22", "Wave_HT_23", "Wave_HT_24", "Wave_HT_25", "Wave_HT_26", "Wave_HT_27", "Wave_HT_28", "Wave_HT_29", "Wave_HT_30", "Wave_HT_31", "Wave_HT_32", "Wave_MP4xSaw1", "Wave_MP4xSaw2", "Wave_MPSawA1", "Wave_MPSawA2", "Wave_MPSawA3", "Wave_MPSawA4", "Wave_MPSawB1", "Wave_MPSawB2", "Wave_MPSawB3", "Wave_MPSqr_1", "Wave_MPSqr_2", "Wave_MPSqr_3", "Wave_MPSqr_4", "Wave_MPSqr_5", "Wave_MPTri", "Wave_Noise", "Wave_Noise1", "Wave_Noise2", "Wave_Noise3", "Wave_Noise4", "Wave_Pulse1", "Wave_Pulse2", "Wave_Pulse3", "Wave_Saw", "Wave_Sine"];

var Maps = [];

Maps.push(Bass);
Maps.push(BellKey);
Maps.push(FX);
Maps.push(KitSeq);
Maps.push(Lead);
Maps.push(Misc);
Maps.push(Pad);
Maps.push(Waves);

var SMAPS = ["Bass", "Bells & Keys", "FX","Kits & Seq", "Leads", "Misc", "Pads", "Basic Waves"];


// BANK A
BankA.set("items", "");
BankA.set("items", maps.join("\n"));
const var WAVELABEL1 = Content.getComponent("WAVELABEL1");



inline function onBankAControl(component, value)
{
	WAVELABEL1.set("text",BankA.get("items").split("\n")[value-1]);
	
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA").setControlCallback(onBankAControl);

const var Categories = Content.getComponent("Categories");


Categories.set("items", SMAPS.join("\n"));

inline function onCategoriesControl(component, value)
{

	BankA.set("items", [].join("\n")); 
	BankA.set("items", Maps[value-1].join("\n"));
	BankA.setValue(1);
	

};

Content.getComponent("Categories").setControlCallback(onCategoriesControl);




Settings.setVoiceMultiplier(8);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");





const var SampleLoad = [Content.getComponent("SAMPLE"),
                        Content.getComponent("WAVE6"),
                        Content.getComponent("Categories"),
                        Content.getComponent("BankA")];


const var HARMONIC = Synth.getEffect("HARMONIC");
const var OscWave = Content.getComponent("OscWave");
const var ScriptPanel1 = Content.getComponent("ScriptPanel1");
const var ScriptPanel3 = Content.getComponent("ScriptPanel3");
const var ScriptPanel6 = Content.getComponent("ScriptPanel6");


const var UserParam = Content.getComponent("UserParam");



inline function onOscWaveControl(component, value)
{

	if(value == 1)
	{	 
	    HARMONIC.setAttribute(HARMONIC.SampleOSc, 0);
	    
	    
	    for(s in SampleLoad)
	           s.showControl(0);
	           ScriptPanel6.showControl(1);
	           ScriptPanel1.showControl(0);
	           ScriptPanel3.showControl(0);
	    UserParam.showControl(0);

	}
	
		if(value == 2)
	{
		HARMONIC.setAttribute(HARMONIC.SampleOSc, 1);
		for(s in SampleLoad)
			         ScriptPanel6.showControl(1);
			         	           ScriptPanel1.showControl(0);
	UserParam.showControl(0);		           	          
	 ScriptPanel3.showControl(0);

	}
	
			if(value == 3)
		{
			HARMONIC.setAttribute(HARMONIC.SampleOSc, 2);
			UserParam.showControl(0);
			for(s in SampleLoad)
				           s.showControl(0);
				          ScriptPanel6.showControl(1);
	           ScriptPanel1.showControl(0);
				           	           ScriptPanel3.showControl(0);

	
		}
		
		if(value == 4)
			{
				HARMONIC.setAttribute(HARMONIC.SampleOSc, 3);
				UserParam.showControl(0);
				for(s in SampleLoad)
					           s.showControl(0);
		ScriptPanel6.showControl(1);
	           ScriptPanel1.showControl(0);
			           ScriptPanel3.showControl(0);
		
			}
			
			if(value == 5)
				{
					HARMONIC.setAttribute(HARMONIC.SampleOSc, 4);
					UserParam.showControl(0);
					for(s in SampleLoad)
						           s.showControl(0);
						           ScriptPanel6.showControl(1);
	           ScriptPanel1.showControl(0);
						           	           ScriptPanel3.showControl(0);
			
			
				}
				
				if(value == 6)
						{
							HARMONIC.setAttribute(HARMONIC.SampleOSc, 5);
				   for(s in SampleLoad)
	           s.showControl(1);
	         UserParam.showControl(0);
	           ScriptPanel1.showControl(1);
	           ScriptPanel6.showControl(0);
	           ScriptPanel3.showControl(0);
					
						}
			if(value == 7)
								{
									HARMONIC.setAttribute(HARMONIC.SampleOSc, 6);
						   for(s in SampleLoad)
			           s.showControl(0);
			          ScriptPanel1.showControl(0);
			          	           ScriptPanel6.showControl(0);
			          	           ScriptPanel3.showControl(1);
							UserParam.showControl(1);
								}	
	if(value == 8)
							{
								HARMONIC.setAttribute(HARMONIC.SampleOSc, 7);
					   for(s in SampleLoad)
		           s.showControl(0);
		       ScriptPanel1.showControl(0);
			          	           ScriptPanel6.showControl(0);
			          	           ScriptPanel3.showControl(1);
						UserParam.showControl(1);
							}		
		if(value == 9)
								{
									HARMONIC.setAttribute(HARMONIC.SampleOSc, 8);
						   for(s in SampleLoad)
			           s.showControl(0);
			      ScriptPanel1.showControl(0);
			          	           ScriptPanel6.showControl(0);
			          	           ScriptPanel3.showControl(1);
							UserParam.showControl(1);
								}																
};

Content.getComponent("OscWave").setControlCallback(onOscWaveControl);



inline function onSOURC3Control(component, value)
{
	HARMONIC.setAttribute(HARMONIC.HarmLfoSrc, value-1);
};

Content.getComponent("SOURC3").setControlCallback(onSOURC3Control);


inline function onSOURC5Control(component, value)
{
		HARMONIC.setAttribute(HARMONIC.HarmEnvSrc, value-1);
};

Content.getComponent("SOURC5").setControlCallback(onSOURC5Control);


inline function onSOURC18Control(component, value)
{
		HARMONIC.setAttribute(HARMONIC.Detuneenvsrc, value-1);
};

Content.getComponent("SOURC18").setControlCallback(onSOURC18Control);


inline function onSOURC19Control(component, value)
{	
HARMONIC.setAttribute(HARMONIC.DetuneLFOsrc, value-1);

};

Content.getComponent("SOURC19").setControlCallback(onSOURC19Control);


inline function onSOURC4Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.FXLfoSrc, value-1);
};

Content.getComponent("SOURC4").setControlCallback(onSOURC4Control);


inline function onSOURC6Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.FxEnvSrc, value-1);
};

Content.getComponent("SOURC6").setControlCallback(onSOURC6Control);


inline function onScriptComboBox1Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.utEnvSrc, value-1);
};

Content.getComponent("ScriptComboBox1").setControlCallback(onScriptComboBox1Control);


inline function onScriptComboBox4Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.CutLfoSrc, value-1);
};

Content.getComponent("ScriptComboBox4").setControlCallback(onScriptComboBox4Control);


inline function onScriptComboBox8Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.MixSrc, value-1);
};

Content.getComponent("ScriptComboBox8").setControlCallback(onScriptComboBox8Control);


inline function onScriptComboBox9Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.MixLfoSrc, value-1);
};

Content.getComponent("ScriptComboBox9").setControlCallback(onScriptComboBox9Control);


inline function onScriptComboBox10Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.qEnvSrc, value-1);
};

Content.getComponent("ScriptComboBox10").setControlCallback(onScriptComboBox10Control);


inline function onScriptComboBox11Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.qLfoSrc, value-1);
};

Content.getComponent("ScriptComboBox11").setControlCallback(onScriptComboBox11Control);

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



inline function onScriptComboBox3Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.FilterType, value-1);
};

Content.getComponent("ScriptComboBox3").setControlCallback(onScriptComboBox3Control);

//SP Controls

const Tm = Engine.createAndRegisterSliderPackData(6);     
const var Raindrops = Synth.getSliderPackProcessor("HARMONIC").getSliderPack(6);
Tm.linkTo(Raindrops);
        
const var UserControls =[];

for (i = 0; i < 8; i++)
{
    UserControls[i] = Content.getComponent("User"+(i+1));
    UserControls[i].setControlCallback(TrigMode);
}
     
     inline function TrigMode(component, value)
     {    
         local idx = UserControls.indexOf(component); 
        
         {  
         
         	Tm.setValue(idx, value);
       
     }
     
}       

const Tm2 = Engine.createAndRegisterSliderPackData(10);     
const var Raindrops2 = Synth.getSliderPackProcessor("HARMONIC").getSliderPack(10);
Tm2.linkTo(Raindrops2);
        
const var UserControls2 =[];

for (i = 0; i < 3; i++)
{
    UserControls2[i] = Content.getComponent("UserB"+(i+1));
    UserControls2[i].setControlCallback(TrigMode2);
}
     
     inline function TrigMode2(component, value)
     {    
         local idx = UserControls2.indexOf(component); 
        
         {  
         
         	Tm2.setValue(idx, value);
       
     }
     
}       

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
 