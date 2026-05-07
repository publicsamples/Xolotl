 Synth.deferCallbacks(true);

// Complex UI components that carry heavy `data` payloads.
const var COMPLEX_PRESET_IDS = [
	"ModSp1", "ModSp2", "ModSp3",
	"ModTable1", "ModTable2",
	"ScriptSliderPack1", "ScriptSliderPack2", "ScriptSliderPack3",
	"SliderPack1", "SliderPack2", "SliderPack3", "SliderPack4", "SliderPack5",
	"pitch-sp4", "pitch-sp5", "pitch-sp6", "pitch-sp7"
];

inline function isComplexPresetId(id)
{
	return COMPLEX_PRESET_IDS.indexOf(id) != -1;
}

inline function setComplexPresetSavingEnabled(shouldSaveInPreset)
{
	for (id in COMPLEX_PRESET_IDS)
	{
		local c = Content.getComponent(id);
		if (isDefined(c))
			c.set("saveInPreset", shouldSaveInPreset);
	}
}

setComplexPresetSavingEnabled(true);

inline function onOscWaveControl(component, value)
{
	if (!isDefined(value))
		return;

	if (g_presetRestoreBusy)
		return;

	if (!isDefined(HARMONIC) || !isDefined(OSC) || !isDefined(MULTI) || !isDefined(USER))
		return;

	Engine.allNotesOff();


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
if (!isDefined(value))
	return;

if (!isDefined(LFO1))
	return;

LFO1.setAttribute(LFO1.Modifiers, value-1);
};

Content.getComponent("ComboBox1").setControlCallback(onComboBox1Control);


inline function onComboBox2Control(component, value)
{
if (!isDefined(value))
	return;

if (!isDefined(LFO2))
	return;

LFO2.setAttribute(LFO2.Modifiers, value-1);
};

Content.getComponent("ComboBox2").setControlCallback(onComboBox2Control);


inline function onComboBox3Control(component, value)
{
if (!isDefined(value))
	return;

if (!isDefined(LFO3))
	return;

LFO3.setAttribute(LFO3.Modifiers, value-1);
};

Content.getComponent("ComboBox3").setControlCallback(onComboBox3Control);


inline function onOscWave1Control(component, value)
{
	if (!isDefined(value))
		return;

	if (!isDefined(HARMONIC))
		return;

	Engine.allNotesOff();

 HARMONIC.setAttribute(HARMONIC.OscType, value);
};

Content.getComponent("OscWave1").setControlCallback(onOscWave1Control);

const var Stages = Content.getComponent("Stages");


inline function onStagesControl(component, value)
{
	if (!isDefined(value))
		return;

	if (!isDefined(HARMONIC))
		return;

		if(value == 1)
		{	 
		Engine.allNotesOff();
			HARMONIC.setAttribute(HARMONIC.V1, 4);
			HARMONIC.setAttribute(HARMONIC.V2, 4);
			HARMONIC.setAttribute(HARMONIC.V3, 4);
			HARMONIC.setAttribute(HARMONIC.V5, 5);
			
			}
		if(value == 2)
				{	 
				Engine.allNotesOff();
			HARMONIC.setAttribute(HARMONIC.V1, 8);
			HARMONIC.setAttribute(HARMONIC.V2, 8);
			HARMONIC.setAttribute(HARMONIC.V3, 8);
			HARMONIC.setAttribute(HARMONIC.V5, 9);
					}	
		if(value == 3)
						{	
						Engine.allNotesOff(); 
			HARMONIC.setAttribute(HARMONIC.V1, 16);
			HARMONIC.setAttribute(HARMONIC.V2, 16);
			HARMONIC.setAttribute(HARMONIC.V3, 16);
			HARMONIC.setAttribute(HARMONIC.V5, 17);
							}				
			if(value == 4)
							{	 
							Engine.allNotesOff();
					HARMONIC.setAttribute(HARMONIC.V1, 24);
			HARMONIC.setAttribute(HARMONIC.V2, 24);
			HARMONIC.setAttribute(HARMONIC.V3, 24);
			HARMONIC.setAttribute(HARMONIC.V5, 25);
								}	
	if(value == 5)
							{	
							Engine.allNotesOff(); 
			HARMONIC.setAttribute(HARMONIC.V1, 32);
			HARMONIC.setAttribute(HARMONIC.V2, 32);
			HARMONIC.setAttribute(HARMONIC.V3, 32);
			HARMONIC.setAttribute(HARMONIC.V5, 32);
								}								
};

Content.getComponent("Stages").setControlCallback(onStagesControl);

const var ModSp1 = Content.getComponent("ModSp1");
const var ModSp2 = Content.getComponent("ModSp2");
const var ModSp3 = Content.getComponent("ModSp3");


inline function onModShapeControl(component, value)
{


	if(value == 1)
		{
	HARMONIC.setAttribute(HARMONIC.FxSinSh, 1);
	ModSp1.showControl(1);
	ModSp2.showControl(0);
	ModSp3.showControl(0);
    	}
	if(value == 2)
		{
	HARMONIC.setAttribute(HARMONIC.FxSinSh, 2);
	ModSp1.showControl(1);
	ModSp2.showControl(0);
	ModSp3.showControl(0);
    	}
	if(value == 3)
		{
	HARMONIC.setAttribute(HARMONIC.FxSinSh, 3);
	ModSp1.showControl(1);
	ModSp2.showControl(0);
	ModSp3.showControl(0);
	}
	if(value == 4)
    	{
    	HARMONIC.setAttribute(HARMONIC.FxSinSh, 4);
    	ModSp1.showControl(1);
    	ModSp2.showControl(0);
    	ModSp3.showControl(0);
    	
    	    	}
	if(value == 5)
		{
	HARMONIC.setAttribute(HARMONIC.FxSinSh, 5);
	ModSp1.showControl(0);
	ModSp2.showControl(1);
	ModSp3.showControl(1);

    	}

};

Content.getComponent("ModShape").setControlCallback(onModShapeControl);






//const var SilentSynth1 = Synth.getChildSynth("Silent Synth1");

const var SynthesiserGroup1 = Synth.getChildSynth("HARMONIC");

//mod buttons 

const var EnvSliders1 = Content.getComponent("EnvSliders1");
const var ModTable1 = Content.getComponent("ModTable1");


inline function onModMode1Control(component, value)
{
	if (!isDefined(value))
		return;

	if (!isDefined(HARMONIC) || !isDefined(EnvSliders1) || !isDefined(ModTable1))
		return;

	EnvSliders1.showControl(value-1);
	ModTable1.showControl(value);
	HARMONIC.setAttribute(HARMONIC.EnvMode1, value);
};

Content.getComponent("ModMode1").setControlCallback(onModMode1Control);

//mod buttons 

const var EnvSliders2 = Content.getComponent("EnvSliders2");
const var ModTable2 = Content.getComponent("ModTable2");


inline function onModMode2Control(component, value)
{
	EnvSliders2.showControl(value-1);
	ModTable2.showControl(value);
	HARMONIC.setAttribute(HARMONIC.EnvMode2, value);
};

Content.getComponent("ModMode2").setControlCallback(onModMode2Control);
