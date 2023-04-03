Content.makeFrontInterface(905, 565);


include("factory_waves.js");
include("UISTUFF.js");
include("ExpansionWaves.js");


var Maps = [];
//Maps.push(BasicWaveforms);
//Maps.push(GM);
//Maps.push(Hybrids);
//Maps.push(Kits);
//Maps.push(cs30);
//Maps.push(em25);
//Maps.push(sys101);
//Maps.push(jx3p);
//Maps.push(kraftzwerg);
//Maps.push(XPFM);
//Maps.push(XPMisc);
//Maps.push(XPPWM);
//Maps.push(XPSaws);
//Maps.push(XPSquares);
//Maps.push(XPtriangles);
Maps.push(Monopoly);

var SMAPS = ["Monopoly"];

//var SMAPS = ["BasicWaveforms", "GM", "Hybrids", "Kits", "cs30", "em25", "sys101","jx3p", "kraftzwerg", "XPFM", "XPMisc","XPPWM", "XPSaws", "XPSquares", "Monopoly"];

//var SMAPS = ["BasicWaveforms", "GM", "Hybrids", "Kits"];

var Cats = [];

Cats.push(SMAPS);


Settings.setVoiceMultiplier(8);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);


const var HARMONIC = Synth.getChildSynth("HARMONIC")

const var BankA = Content.getComponent("BankA");

const var BankA1 = Content.getComponent("BankA1");

const var WAVELABEL1 = Content.getComponent("WAVELABEL1");
const var WAVELABEL2 = Content.getComponent("WAVELABEL2");

// BANK A

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



// BANK A1


inline function onBankA1Control(component, value)
{
	WAVELABEL2.set("text",BankA1.get("items").split("\n")[value-1]);
	slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
	

};

Content.getComponent("BankA1").setControlCallback(onBankA1Control);

const var Categories1 = Content.getComponent("Categories1");

Categories1.set("items", SMAPS.join("\n"));

inline function onCategories1Control(component, value)
{

	BankA1.set("items", [].join("\n")); 
	BankA1.set("items", Maps[value-1].join("\n"));
	BankA1.setValue(1);

};

Content.getComponent("Categories1").setControlCallback(onCategories1Control);

Content.getComponent("LoadSFZ1").setControlCallback(onLoadSFZ1Control);


inline function onLoadSFZ1Control(component, value)
{
	if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slot.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		WAVELABEL1.set("text", "USER");
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
		

		slot1.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		WAVELABEL2.set("text", "USER");
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
 