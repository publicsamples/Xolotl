Content.makeFrontInterface(600, 600);


const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);
const slot2 = harm.getAudioFile(2);
const slot3 = harm.getAudioFile(3);

const var HARMONIC = Synth.getChildSynth("HARMONIC")
const var BankA = Content.getComponent("BankA");
const var BankA1 = Content.getComponent("BankA1");
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




inline function onExpansionSelectorControl(component, value)
{
	local expansionToLoad = component.getItemText();
	

	if(expansionToLoad == expansionNames[0])
        expansionToLoad = "";
    
	expHandler.setCurrentExpansion(expansionToLoad);
};

Content.getComponent("ExpansionSelector").setControlCallback(onExpansionSelectorControl);

var sampleMaps = Sampler.getSampleMapList();
var sampleMapsed = Sampler.getSampleMapList();



inline function newcombobox(newExpansion)
{

       if(isDefined(newExpansion))
        
       
    {
        local cx = expHandler.getCurrentExpansion();
        sampleMaps = cx.getSampleMapList();
        sampleMapsed = cx.getSampleMapList();
        local expansionProps = cx.getProperties();
        local expName = expansionProps.Name;
        
        for (i = 0; i < sampleMapsed.length; i++)
        {
        sampleMapsed[i] = sampleMapsed[i].replace("{EXP::");
     sampleMapsed[i] = sampleMapsed[i].replace("}");
       sampleMapsed[i] = sampleMapsed[i].replace(expName);

        }
       
        BankA.set("items", "");
        BankA.set("items", sampleMapsed.join("\n"));


    }
    
    else
    
    {
        sampleMaps = Sampler.getSampleMapList();
        BankA1.set("items", "");
        BankA1.set("items", sampleMaps.join("\n"));

    }
    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);


inline function onBankAControl(component, value)
{

  slot.loadFile("{XYZ::SampleMap}" + "{EXP::Expansion}" + component.getItemText());

//  	slot.setFile(Maps[value-1]);
};

Content.getComponent("BankA").setControlCallback(onBankAControl);



inline function onBankA1Control(component, value)
{
slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA1").setControlCallback(onBankA1Control);


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
 