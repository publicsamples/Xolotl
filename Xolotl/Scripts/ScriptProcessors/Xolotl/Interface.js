Content.makeFrontInterface(850, 580);

//const var rm = Engine.getGlobalRoutingManager();

//include("UISTUFF.js");

const var PRESETS = Content.getComponent("PRESETS");

const var PRESETBUTTON = Content.getComponent("PRESETBUTTON");


inline function onPRESETBUTTONControl(component, value)
{

      PRESETS.showControl(value);
};

Content.getComponent("PRESETBUTTON").setControlCallback(onPRESETBUTTONControl);



const var AudioList = Engine.loadAudioFilesIntoPool();

const var SampleA = Content.getComponent("SampleA");
const var SampleBank = Content.getComponent("SampleBank");

const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);

const var foldersV1 = [];        // Top-level Genre foldersV1
const var instrumentsV1 = {};    // Maps Genre to Instruments
const var samplesV1 = {};  



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

include("Samples.js");
include("Controls.js");
include("Presets.js");





//presets


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
 