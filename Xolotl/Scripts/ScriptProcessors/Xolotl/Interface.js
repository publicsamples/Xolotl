Content.makeFrontInterface(945, 605);

include("UISTUFF.js");

<<<<<<< HEAD
// BANK 
=======
const eventdata = rm.getEventData(0, 0);

const cable1 = rm.getCable("mod1");
const cable2 = rm.getCable("mod2");
const cable3 = rm.getCable("mod3");

const var User1 = Content.getComponent("User1");

User1.setRange(0.2, 1, 0.2);
>>>>>>> d2

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


<<<<<<< HEAD
=======
inline function onSOURC3Control(component, value)
{
	HARMONIC.setAttribute(HARMONIC.HarmLfoSrc, value-1);
};

Content.getComponent("SOURC3").setControlCallback(onSOURC3Control);


inline function onSOURC5Control(component, value)
{
		HARMONIC.setAttribute(HARMONIC.HarmEnvSrc, value-1);
};

Content.getComponent("SOURC5").setControlCallback(onSOURC5Control);


inline function onSOURC18Control(component, value)
{
		HARMONIC.setAttribute(HARMONIC.Detuneenvsrc, value-1);
};

Content.getComponent("SOURC18").setControlCallback(onSOURC18Control);


inline function onSOURC19Control(component, value)
{	
HARMONIC.setAttribute(HARMONIC.DetuneLFOsrc, value-1);

};

Content.getComponent("SOURC19").setControlCallback(onSOURC19Control);


inline function onSOURC4Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.FXLfoSrc, value-1);
};

Content.getComponent("SOURC4").setControlCallback(onSOURC4Control);


inline function onSOURC6Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.FxEnvSrc, value-1);
};

Content.getComponent("SOURC6").setControlCallback(onSOURC6Control);


inline function onScriptComboBox1Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.utEnvSrc, value-1);
};

Content.getComponent("ScriptComboBox1").setControlCallback(onScriptComboBox1Control);


inline function onScriptComboBox4Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.CutLfoSrc, value-1);
};

Content.getComponent("ScriptComboBox4").setControlCallback(onScriptComboBox4Control);


inline function onScriptComboBox8Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.MixSrc, value-1);
};

Content.getComponent("ScriptComboBox8").setControlCallback(onScriptComboBox8Control);


inline function onScriptComboBox9Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.MixLfoSrc, value-1);
};

Content.getComponent("ScriptComboBox9").setControlCallback(onScriptComboBox9Control);


inline function onScriptComboBox10Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.qEnvSrc, value-1);
};

Content.getComponent("ScriptComboBox10").setControlCallback(onScriptComboBox10Control);


inline function onScriptComboBox11Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.qLfoSrc, value-1);
};

Content.getComponent("ScriptComboBox11").setControlCallback(onScriptComboBox11Control);

const var LFO1 = Synth.getModulator("LFO1");
const var LFO2 = Synth.getModulator("LFO2");
const var LFO3 = Synth.getModulator("LFO3");


inline function onComboBox1Control(component, value)
{
LFO1.setAttribute(LFO1.Modifiers, value-1);
};

Content.getComponent("ComboBox1").setControlCallback(onComboBox1Control);


inline function onComboBox2Control(component, value)
{
LFO2.setAttribute(LFO2.Modifiers, value-1);
};

Content.getComponent("ComboBox2").setControlCallback(onComboBox2Control);


inline function onComboBox3Control(component, value)
{
LFO3.setAttribute(LFO3.Modifiers, value-1);
};

Content.getComponent("ComboBox3").setControlCallback(onComboBox3Control);



inline function onScriptComboBox3Control(component, value)
{
HARMONIC.setAttribute(HARMONIC.FilterType, value-1);
};

Content.getComponent("ScriptComboBox3").setControlCallback(onScriptComboBox3Control);

//SP Controls

const Tm = Engine.createAndRegisterSliderPackData(6);     
const var Raindrops = Synth.getSliderPackProcessor("HARMONIC").getSliderPack(6);
Tm.linkTo(Raindrops);
        
const var UserControls =[];

for (i = 0; i < 8; i++)
{
    UserControls[i] = Content.getComponent("User"+(i+1));
    UserControls[i].setControlCallback(TrigMode);
}
     
     inline function TrigMode(component, value)
     {    
         local idx = UserControls.indexOf(component); 
        
         {  
         
         	Tm.setValue(idx, value);
       
     }
     
}       
>>>>>>> d2

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
 