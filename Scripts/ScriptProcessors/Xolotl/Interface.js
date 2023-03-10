Content.makeFrontInterface(905, 565);


include("factory_waves.js");
include("UISTUFF.js");
include("ExpansionWaves.js");


var Maps = [];

Maps.push(cs30);
Maps.push(em25);
Maps.push(sys101);
Maps.push(jx3p);
Maps.push(hybrids);
Maps.push(kraftzwerg);
Maps.push(XPFM);
Maps.push(XPMisc);
Maps.push(XPPWM);

var MapsF = [];

MapsF.push(BasicWaveforms);
MapsF.push(GM);
MapsF.push(ModularShape);
MapsF.push(ModularFM);
MapsF.push(ModularFiltered);
MapsF.push(ModularFM);
MapsF.push(Kits);

var SMAPS = ["BasicWaveforms", "GM", "ModularShape","ModularFM", "ModularFiltered", "ModularNoise", "Kits"];

var SMAPSexp = ["cs30", "em25", "sys101","jx3p", "hybrids", "kraftzwerg", "XP-FM", "XP-Misc","XP-PWM" ];



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
const var BankB = Content.getComponent("BankB");
const var BankA1 = Content.getComponent("BankA1");
const var BankB1 = Content.getComponent("BankB1");

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
    

    
const var A = Content.getComponent("A");
const var B = Content.getComponent("B");
const var A1 = Content.getComponent("A1");
const var B1 = Content.getComponent("B1");



inline function onExpansionSelectorControl(component, value)
{

B1.showControl(value); 
        B1.showControl(1-value);

	local expansionToLoad = component.getItemText();
	

	if(expansionToLoad == expansionNames[0])
        expansionToLoad = "";
    
	expHandler.setCurrentExpansion(expansionToLoad);

};

Content.getComponent("ExpansionSelector").setControlCallback(onExpansionSelectorControl);

var sampleMaps = Sampler.getSampleMapList();
var sampleMapsed = Sampler.getSampleMapList();

// BANK A
BankA.set("items", "");
BankA.set("items", maps.join("\n"));

inline function onBankAControl(component, value)
{
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


// BANK A1
BankA1.set("items", "");
BankA1.set("items", maps.join("\n"));

inline function onBankA1Control(component, value)
{
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

// BANK B
BankB1.set("items", "");
BankB1.set("items", maps.join("\n"));

inline function onBankB1Control(component, value)
{
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
 