Content.makeFrontInterface(905, 565);


include("factory_waves.js");
include("UISTUFF.js");
include("ExpansionWaves.js");
include("Migration.js");
include("SampleLoadSave.js");
include("PitchDetector.js");
include("LoopPointDragger.js");


var Maps = [];

Maps.push(cs30);
Maps.push(em25);
Maps.push(sys101);
Maps.push(jx3p);
Maps.push(kraftzwerg);
Maps.push(XPFM);
Maps.push(XPMisc);
Maps.push(XPPWM);
Maps.push(XPSaws);
Maps.push(XPSquares);
Maps.push(XPtriangles);

var MapsF = [];

MapsF.push(BasicWaveforms);
MapsF.push(GM);
MapsF.push(Hybrids);
MapsF.push(Kits);



var SMAPS = ["BasicWaveforms", "GM", "Hybrids", "Kits"];

var SMAPSexp = ["cs30", "em25", "sys101","jx3p", "kraftzwerg", "XPFM", "XPMisc","XPPWM", "XPSaws", "XPSquares","XPtriangles"  ];



var Cats = [];

Cats.push(SMAPS);


Settings.setVoiceMultiplier(8);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const user = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);


const var HARMONIC = Synth.getChildSynth("HARMONIC")

const var BankA = Content.getComponent("BankA");
const var BankB = Content.getComponent("BankB");
const var BankC = Content.getComponent("BankC");
const var BankA1 = Content.getComponent("BankA1");
const var BankB1 = Content.getComponent("BankB1");
const var BankC1 = Content.getComponent("BankC1");

const var ExpansionSelector = Content.getComponent("ExpansionSelector");

const var expHandler = Engine.createExpansionHandler();

const var expansions = expHandler.getExpansionList();

expHandler.setAllowedExpansionTypes([expHandler.FileBased, 
                                     expHandler.Intermediate, 
                                     expHandler.Encrypted]);

                                     
const var expansionNames = [];

reg hr;
inline function onLoadExpControl(component, value)
{
    if (value)
    {
        FileSystem.browse("", false, "", function(result)
        {
            hr = result;
	        
            FileSystem.browseForDirectory("", function(dir)
            {
                expHandler.installExpansionFromPackage(hr, dir);
            });
        });
    }
};

Content.getComponent("LoadExp").setControlCallback(onLoadExpControl);

expansionNames.push("FACTORY");

for(e in expHandler.getExpansionList())
    expansionNames.push(e.getProperties().Name);


ExpansionSelector.set("items", expansionNames.join("\n"));

const var importlabel = Content.getComponent("importlabel");




inline function onExpansionSelectorControl(component, value)
{
	local expansionToLoad = component.getItemText();
	

	if(expansionToLoad == expansionNames[0])
        expansionToLoad = "";
    
	expHandler.setCurrentExpansion(expansionToLoad);
	
	for (i = 0; i < Panels.length; i++)
	       Panels[i].showControl(value - 1 == i);
	       
	for (i = 0; i < Panels.length; i++)
	      Panels1[i].showControl(value - 1 == i);
	   
	       //     SAMPLELOADING.showControl(value); 
	      //       SAMPLELOADING.showControl(1-value); 
	     //        importlabel.showControl(value); 
	     //        importlabel.showControl(1-value); 
};

Content.getComponent("ExpansionSelector").setControlCallback(onExpansionSelectorControl);

var sampleMaps = Sampler.getSampleMapList();
var sampleMapsed = Sampler.getSampleMapList();



inline function newcombobox(newExpansion)
{

       if(isDefined(newExpansion))
        
       
    {  local cx = expHandler.getCurrentExpansion();
       sampleMaps = cx.getSampleMapList();
       sampleMapsed = cx.getSampleMapList();
       local expansionProps = cx.getProperties();
       local expName = expansionProps.Name;

for (i = 0; i < sampleMapsed.length; i++)
       {
     //  sampleMapsed[i] = sampleMapsed[i].replace("{EXP::");
   //    sampleMapsed[i] = sampleMapsed[i].replace("}");
   //    sampleMapsed[i] = sampleMapsed[i].replace(expName);

       }

       BankC.set("items", "");
       BankC.set("items", sampleMapsed.join("\n"));
     
   }
   else
   {
   
      sampleMaps = Sampler.getSampleMapList();
      BankC.set("items", "");
      BankC.set("items", sampleMaps.join("\n"));
   }


    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);
    
// Panels Array //
const var Panels = [];

Panels[0] = Content.getComponent("A");
Panels[1] = Content.getComponent("B");
//[2] = Content.getComponent("C");

const var Panels1 = [];

Panels1[0] = Content.getComponent("A1");
Panels1[1] = Content.getComponent("B1");
//Panels1[2] = Content.getComponent("C1");




// BANK A
BankA.set("items", "");
BankA.set("items", maps.join("\n"));


const var WAVELABEL1 = Content.getComponent("WAVELABEL1");

const var WAVELABEL2 = Content.getComponent("WAVELABEL2");

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
	BankA.set("items", MapsF[value-1].join("\n"));
	BankA.setValue(1);
	

};

Content.getComponent("Categories").setControlCallback(onCategoriesControl);

// BANK B
BankB.set("items", "");
BankB.set("items", maps.join("\n"));

inline function onBankBControl(component, value)
{
	WAVELABEL1.set("text",BankB.get("items").split("\n")[value-1]);
	

	slot.loadFile("{XYZ::SampleMap}" + "{EXP::Expansion}" +  component.getItemText());
};

Content.getComponent("BankB").setControlCallback(onBankBControl);

const var CategoriesB = Content.getComponent("CategoriesB");

CategoriesB.set("items", SMAPSexp.join("\n"));

inline function onCategoriesBControl(component, value)
{

	BankB.set("items", [].join("\n")); 
	BankB.set("items", Maps[value-1].join("\n"));
	BankB.setValue(1);

};

Content.getComponent("CategoriesB").setControlCallback(onCategoriesBControl);


// BANK C



inline function onBankCControl(component, value)
{
	
WAVELABEL1.set("text",BankC.get("items").split("\n")[value-1].replace("EXP::","").replace("}").replace(expName).replace("{").replace("User"));
	
Sampler1.loadSampleMap(sampleMaps[value-1]);
slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankC").setControlCallback(onBankCControl);





// BANK A1
BankA1.set("items", "");
BankA1.set("items", maps.join("\n"));

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
	BankA1.set("items", MapsF[value-1].join("\n"));
	BankA1.setValue(1);



};

Content.getComponent("Categories1").setControlCallback(onCategories1Control);

// BANK B1
BankB1.set("items", "");
BankB1.set("items", maps.join("\n"));

inline function onBankB1Control(component, value)
{
	WAVELABEL2.set("text",BankB1.get("items").split("\n")[value-1]);

	slot1.loadFile("{XYZ::SampleMap}" + "{EXP::Expansion}" +  component.getItemText());
};

Content.getComponent("BankB1").setControlCallback(onBankB1Control);

const var CategoriesB1 = Content.getComponent("CategoriesB1");

CategoriesB1.set("items", SMAPSexp.join("\n"));

inline function onCategoriesB1Control(component, value)
{

	BankB1.set("items", [].join("\n")); 
	BankB1.set("items", Maps[value-1].join("\n"));
	BankB1.setValue(1);

};

Content.getComponent("CategoriesB1").setControlCallback(onCategoriesB1Control);

// BANK C1



inline function onBankC1Control(component, value)
{
	
WAVELABEL2.set("text",BankC1.get("items").split("\n")[value-1].replace("EXP::","").replace("}").replace(expName).replace("{").replace("User"));
	
Sampler1.loadSampleMap(sampleMaps[value-1]);
slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankC1").setControlCallback(onBankC1Control);

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
 