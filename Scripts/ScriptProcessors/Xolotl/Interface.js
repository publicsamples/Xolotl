Content.makeFrontInterface(800, 670);
Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);
const slot2 = harm.getAudioFile(2);

const var HARMONIC = Synth.getChildSynth("HARMONIC");

const var SAMPLE = Content.getComponent("SAMPLE");
SAMPLE.set("items", "");
SAMPLE.set("items", maps.join("\n"));

inline function onSAMPLEControl(component, value)
{
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

SAMPLE.setControlCallback(onSAMPLEControl);

const var FMWAVE1 = Content.getComponent("FMWAVE1");
FMWAVE1.set("items", "");
FMWAVE1.set("items", maps.join("\n"));

inline function onFMWAVE1Control(component, value)
{
slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());

};

Content.getComponent("FMWAVE1").setControlCallback(onFMWAVE1Control);

const var FMWAVE2 = Content.getComponent("FMWAVE2");
FMWAVE2.set("items", "");
FMWAVE2.set("items", maps.join("\n"));

inline function onFMWAVE2Control(component, value)
{
	slot2.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("FMWAVE2").setControlCallback(onFMWAVE2Control);


const var modtype1 = Content.getComponent("modtype1");
const var slidermod1 = Content.getComponent("slidermod1");
const var Table1 = Content.getComponent("Table1");


inline function onmodtype1Control(component, value)
{
	Table1.showControl(value); 
        slidermod1.showControl(1-value);
        HARMONIC.setAttribute(HARMONIC.typ1, 0);
        HARMONIC.setAttribute(HARMONIC.typ1,1-value);
};

Content.getComponent("modtype1").setControlCallback(onmodtype1Control);

const var modtype2 = Content.getComponent("modtype2");
const var slidermod2 = Content.getComponent("slidermod2");
const var Table2 = Content.getComponent("Table2");


inline function onmodtype2Control(component, value)
{
	Table2.showControl(value); 
        slidermod2.showControl(1-value);
        HARMONIC.setAttribute(HARMONIC.type2, 0);
        HARMONIC.setAttribute(HARMONIC.type2,1-value);
};

Content.getComponent("modtype2").setControlCallback(onmodtype2Control);

const var PRESETS = Content.getComponent("PRESETS");

const var PRESETBUTTON = Content.getComponent("PRESETBUTTON");


inline function onPRESETBUTTONControl(component, value)
{
		PRESETS.showControl(value); 
        PRESETS.showControl(1-value);
};

Content.getComponent("PRESETBUTTON").setControlCallback(onPRESETBUTTONControl);

const var mode = Content.getComponent("mode");

const var HARMONICSYNTH = Content.getComponent("HARMONICSYNTH");

const var FMSynth = Content.getComponent("FMSynth");


inline function onmodeControl(component, value)
{
		HARMONICSYNTH.showControl(value);         FMSynth.showControl(1-value);
	 HARMONIC.setAttribute(HARMONIC.synthmode, 0);
	 HARMONIC.setAttribute(HARMONIC.synthmode,1-value);
       
};

Content.getComponent("mode").setControlCallback(onmodeControl);




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
 