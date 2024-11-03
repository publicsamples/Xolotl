Content.makeFrontInterface(850, 580);

const var rm = Engine.getGlobalRoutingManager();

include("UISTUFF.js");

const eventdata = rm.getEventData(0, 0);

const cable1 = rm.getCable("mod1");
const cable2 = rm.getCable("mod2");
const cable3 = rm.getCable("mod3");

const var User1 = Content.getComponent("User1");

User1.setRange(0, 1, 0.2);

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

const var expbox = Content.getComponent("ExpansionSelector");



const var SampleLoad = [Content.getComponent("SAMPLE"),
                        Content.getComponent("WAVE6"),
                        Content.getComponent("ExpansionSelector"),
                        Content.getComponent("BankA")];


const var HARMONIC = Synth.getEffect("HARMONIC");
const var OscWave = Content.getComponent("OscWave");
const var ScriptPanel1 = Content.getComponent("ScriptPanel1");
const var ScriptPanel3 = Content.getComponent("ScriptPanel3");
const var UserParam = Content.getComponent("UserParam");



inline function onOscWaveControl(component, value)
{

	if(value == 1)
	{	 
	    HARMONIC.setAttribute(HARMONIC.SampleOSc, 0);
	    
	    
	    for(s in SampleLoad)
	           s.showControl(0);
	           ScriptPanel1.showControl(1);
	           ScriptPanel3.showControl(0);
	    UserParam.showControl(0);

	}
	
		if(value == 2)
	{
		HARMONIC.setAttribute(HARMONIC.SampleOSc, 1);
		for(s in SampleLoad)
			           s.showControl(0);
			           ScriptPanel1.showControl(1);
	UserParam.showControl(0);		           	          
	 ScriptPanel3.showControl(0);

	}
	
			if(value == 3)
		{
			HARMONIC.setAttribute(HARMONIC.SampleOSc, 2);
			UserParam.showControl(0);
			for(s in SampleLoad)
				           s.showControl(0);
				           ScriptPanel1.showControl(1);
				           	           ScriptPanel3.showControl(0);

	
		}
		
		if(value == 4)
			{
				HARMONIC.setAttribute(HARMONIC.SampleOSc, 3);
				UserParam.showControl(0);
				for(s in SampleLoad)
					           s.showControl(0);
		ScriptPanel1.showControl(1);
			           ScriptPanel3.showControl(0);
		
			}
			
			if(value == 5)
				{
					HARMONIC.setAttribute(HARMONIC.SampleOSc, 4);
					UserParam.showControl(0);
					for(s in SampleLoad)
						           s.showControl(0);
						           ScriptPanel1.showControl(1);
						           	           ScriptPanel3.showControl(0);
			
			
				}
				
				if(value == 6)
						{
							HARMONIC.setAttribute(HARMONIC.SampleOSc, 5);
				   for(s in SampleLoad)
	           s.showControl(1);
	         UserParam.showControl(0);
	           ScriptPanel1.showControl(1);
	           	           ScriptPanel3.showControl(0);
					
						}
			if(value == 7)
								{
									HARMONIC.setAttribute(HARMONIC.SampleOSc, 6);
						   for(s in SampleLoad)
			           s.showControl(0);
			           ScriptPanel1.showControl(0);
			           	           ScriptPanel3.showControl(1);
							UserParam.showControl(1);
								}	
	if(value == 8)
							{
								HARMONIC.setAttribute(HARMONIC.SampleOSc, 7);
					   for(s in SampleLoad)
		           s.showControl(0);
		           ScriptPanel1.showControl(0);
		           	           ScriptPanel3.showControl(1);
						UserParam.showControl(1);
							}		
		if(value == 9)
								{
									HARMONIC.setAttribute(HARMONIC.SampleOSc, 8);
						   for(s in SampleLoad)
			           s.showControl(0);
			           ScriptPanel1.showControl(0);
			           	           ScriptPanel3.showControl(1);
							UserParam.showControl(1);
								}																
};

Content.getComponent("OscWave").setControlCallback(onOscWaveControl);



 inline function onBankAControl(component, value)
 {
 	WAVELABEL1.set("text",BankA.get("items").split("\n")[value-1]);
 	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
 	slot.loadFile("{XYZ::SampleMap}" + (sampleMaps[value-1]));
 };
 
 Content.getComponent("BankA").setControlCallback(onBankAControl);


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
 