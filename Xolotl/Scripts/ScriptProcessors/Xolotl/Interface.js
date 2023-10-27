Content.makeFrontInterface(945, 605);


include("factory_waves.js");
include("UISTUFF.js");
include("ExpansionWaves.js");
// BANK A



var Maps = [];
Maps.push(MiscWaves);
//Maps.push(Stereo);
//Maps.push(HT700_1);
///.push(HT700_2);
//Maps.push(HT700_3);
//Maps.push(hybrids);
//Maps.push(cs30);
//Maps.push(em25);
//Maps.push(MiscRoland);
//Maps.push(kraftzwerg);
//Maps.push(Xpander);
//Maps.push(Monopoly);




//var SMAPS = ["MiscWaves",  "hybrids",  "cs30", "em25", "MiscRoland", "kraftzwerg",  "Xpander", "Monopoly"];

//var SMAPS = ["MiscWaves", "Stereo", "HT700_1", "HT700_2", "HT700_3"];

var SMAPS = ["MiscWaves"];

const var BankA = Content.getComponent("BankA");
const var WAVELABEL1 = Content.getComponent("WAVELABEL1");
const var Categories = Content.getComponent("Categories");


 inline function onBankAControl(component, value)
 {
 	WAVELABEL1.set("text",BankA.get("items").split("\n")[value-1]);
 	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
 };
 
 Content.getComponent("BankA").setControlCallback(onBankAControl);
 
 
 
 
 
 inline function onCategoriesControl(component, value)
 {
 
 	BankA.set("items", [].join("\n")); 
 	BankA.set("items", Maps[value-1].join("\n"));
 	BankA.setValue(1);
 	Categories.set("items", SMAPS.join("\n"));
 
 };
 
 Content.getComponent("Categories").setControlCallback(onCategoriesControl);
 
 
 


Settings.setVoiceMultiplier(8);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);
const slot2 = harm.getAudioFile(2);
const slot3 = harm.getAudioFile(3);


const var HARMONIC = Synth.getChildSynth("HARMONIC")




const var WAVELABEL1b = Content.getComponent("WAVELABEL1b");



const var AudioWaveform2 = Content.getComponent("AudioWaveform2");



const var A = Content.getComponent("A");
const var B = Content.getComponent("B");
const var C = Content.getComponent("C");

const var User1 = Content.getComponent("User1");

const var ScriptAudioWaveform1 = Content.getComponent("ScriptAudioWaveform1");



inline function onUser1Control(component, value)
{
	


	if(value == 1)
	{	 
	    HARMONIC.setAttribute(HARMONIC.userwav1, 0);
		 A.showControl(1);
		 B.showControl(0);
         C.showControl(0);
	}
	
		if(value == 2)
	{
		HARMONIC.setAttribute(HARMONIC.userwav1, 0.5);
		 A.showControl(0);
		 B.showControl(1);
         C.showControl(0);

	}
	
			if(value == 3)
		{
			HARMONIC.setAttribute(HARMONIC.userwav1, 1);
			 A.showControl(0);
			 B.showControl(0);
	         C.showControl(1);
	
		}
};

Content.getComponent("User1").setControlCallback(onUser1Control);


const var OscWave = Content.getComponent("OscWave");


inline function onOscWaveControl(component, value)
{

	if(value == 1)
	{	 
	    HARMONIC.setAttribute(HARMONIC.OscWave, 0);

	}
	
		if(value == 2)
	{
		HARMONIC.setAttribute(HARMONIC.OscWave, 0.3);

	}
	
			if(value == 3)
		{
			HARMONIC.setAttribute(HARMONIC.OscWave, 0.5);

	
		}
		
		if(value == 4)
			{
				HARMONIC.setAttribute(HARMONIC.OscWave, 0.8);
		
		
			}
			
			if(value == 5)
				{
					HARMONIC.setAttribute(HARMONIC.OscWave, 1);
			
			
				}
};

Content.getComponent("OscWave").setControlCallback(onOscWaveControl);





inline function onLoadSFZ1Control(component, value)
{


	if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slot2.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		WAVELABEL1b.set("text", f.toString(f.NoExtension));
	
	});	

}

}; 

Content.getComponent("LoadSFZ1").setControlCallback(onLoadSFZ1Control);

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
 