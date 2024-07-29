Content.makeFrontInterface(945, 605);

include("UISTUFF.js");

// BANK 

const var expHandler = Engine.createExpansionHandler();
const var expansions = expHandler.getExpansionList();

const var ExpansionSelector = Content.getComponent("ExpansionSelector");
const var BankA = Content.getComponent("BankA");



const var expansionNames = [];

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
        BankA.set("items", "");
        BankA.set("items", sampleMaps.join("\n"));
       

    }
    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);



const var WAVELABEL1 = Content.getComponent("WAVELABEL1");
Settings.setVoiceMultiplier(8);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");


const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);



const var HARMONIC = Synth.getChildSynth("HARMONIC")
const var OscWave = Content.getComponent("OscWave");
const var User1 = Content.getComponent("User1");


inline function onUser1Control(component, value)
{
	


	if(value == 1)
	{	 
	    HARMONIC.setAttribute(HARMONIC.userwav1, 0);
		 BankA.showControl(1);
	
         OscWave.showControl(0);
	}
	
		if(value == 2)
	{
		HARMONIC.setAttribute(HARMONIC.userwav1, 1);
		 BankA.showControl(0);
	
         OscWave.showControl(1);

	}
	
			if(value == 3)
		{
			HARMONIC.setAttribute(HARMONIC.userwav1, 1);
		 BankA.showControl(0);
		 FmPanel.showControl(0);
         OscWave.showControl(1);
	
		}
		
		
					if(value == 4)
				{
					HARMONIC.setAttribute(HARMONIC.userwav1, 1);
				 BankA.showControl(0);
				 FmPanel.showControl(1);
		         OscWave.showControl(1);
			
				}
};

Content.getComponent("User1").setControlCallback(onUser1Control);




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

const var Sampler1 = Synth.getSampler("Sampler1");

 inline function onBankAControl(component, value)
 {
 	WAVELABEL1.set("text",BankA.get("items").split("\n")[value-1]);
 	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
 	slot.loadFile("{XYZ::SampleMap}" + (sampleMaps[value-1]));
 };
 
 Content.getComponent("BankA").setControlCallback(onBankAControl);



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
 