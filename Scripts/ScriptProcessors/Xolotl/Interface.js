Content.makeFrontInterface(800, 650);

const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);

const var SAMPLE = Content.getComponent("SAMPLE");
SAMPLE.set("items", "");
SAMPLE.set("items", maps.join("\n"));

inline function onSAMPLEControl(component, value)
{
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

SAMPLE.setControlCallback(onSAMPLEControl);





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
 