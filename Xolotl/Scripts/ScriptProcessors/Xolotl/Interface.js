Content.makeFrontInterface(945, 605);


include("factory_waves.js");
include("UISTUFF.js");
include("ExpansionWaves.js");
// BANK A


var Maps = [];
Maps.push(BasicWaveforms);
Maps.push(GM);
Maps.push(Hybrids);
Maps.push(cs30);
Maps.push(em25);
Maps.push(sys101);
Maps.push(jx3p);
Maps.push(kraftzwerg);
Maps.push(Xpander);
Maps.push(Monopoly);



var SMAPS = ["BasicWaveforms", "GM", "Hybrids",  "cs30", "em25", "sys101","jx3p", "kraftzwerg",  "Xpander", "Monopoly"];


const var BankA = Content.getComponent("BankA");
const var BankA1 = Content.getComponent("BankA1");
const var WAVELABEL1 = Content.getComponent("WAVELABEL1");
const var WAVELABEL2 = Content.getComponent("WAVELABEL2");
const var Categories = Content.getComponent("Categories");
const var Categories1 = Content.getComponent("Categories1");



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
 
 
 
 // BANK A1
 
 
 inline function onBankA1Control(component, value)
 {
 	WAVELABEL2.set("text",BankA1.get("items").split("\n")[value-1]);
 	slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
 	
 
 };
 
 Content.getComponent("BankA1").setControlCallback(onBankA1Control);
 
 
 
 Categories1.set("items", SMAPS.join("\n"));
 
 inline function onCategories1Control(component, value)
 {
 
 	BankA1.set("items", [].join("\n")); 
 	BankA1.set("items", Maps[value-1].join("\n"));
 	BankA1.setValue(1);
 
 };
 
 Content.getComponent("Categories1").setControlCallback(onCategories1Control);



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

const var WAVELABEL2b = Content.getComponent("WAVELABEL2b");

const var AudioWaveform2 = Content.getComponent("AudioWaveform2");

const var AudioWaveform3 = Content.getComponent("AudioWaveform3");




const var A = Content.getComponent("A");
const var B = Content.getComponent("B");
const var A1 = Content.getComponent("A1");
const var B1 = Content.getComponent("B1");
const var User1 = Content.getComponent("User1");
const var User2 = Content.getComponent("User2");
const var ScriptAudioWaveform1 = Content.getComponent("ScriptAudioWaveform1");
const var ScriptAudioWaveform2 = Content.getComponent("ScriptAudioWaveform2");


inline function onUser1Control(component, value)
{
	
	HARMONIC.setAttribute(HARMONIC.userwav2, value);

	if(value == 0)
	{	 
	    
		 B.showControl(0);
    //     BankA.set("saveInPreset", true);
    //     Categories.set("saveInPreset", true);
//     ScriptAudioWaveform1.set("saveInPreset", false);
   //      WAVELABEL1b.set("saveInPreset", false);
  //       WAVELABEL1.set("saveInPreset", true);
	}
	
		if(value == 1)
	{

	
		  B.showControl(1); 
	  //    BankA.set("saveInPreset", false);
	  //    Categories.set("saveInPreset", false);
	  //    ScriptAudioWaveform1.set("saveInPreset", true);
	 //     WAVELABEL1b.set("saveInPreset", true);
	 //     WAVELABEL1.set("saveInPreset", false);
	}
};

Content.getComponent("User1").setControlCallback(onUser1Control);



inline function onUser2Control(component, value)
{
	HARMONIC.setAttribute(HARMONIC.userwav1, value);

	if(value == 0)
	{
	
		 B1.showControl(0);
        
         
         
	}
	
		if(value == 1)
	{

		  B1.showControl(1);
	  
	}
};

Content.getComponent("User2").setControlCallback(onUser2Control);




inline function onLoadSFZ1Control(component, value)
{


	if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slot2.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		WAVELABEL1b.set("text", "SFZ");
	
	});	

}

}; 

Content.getComponent("LoadSFZ1").setControlCallback(onLoadSFZ1Control);


inline function onLoadSFZ2Control(component, value)
{
	if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slot3.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		WAVELABEL2b.set("text", "SFZ");
	});	
			
}

}; 

Content.getComponent("LoadSFZ2").setControlCallback(onLoadSFZ2Control);




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
 