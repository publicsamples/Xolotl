Content.makeFrontInterface(800, 720);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);


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
   //     sampleMapsed[i] = sampleMapsed[i].replace("{EXP::");
  //   sampleMapsed[i] = sampleMapsed[i].replace("}");
   //    sampleMapsed[i] = sampleMapsed[i].replace(expName);

        }
       
        BankA.set("items", "");
        BankA.set("items", sampleMapsed.join("\n"));
BankA1.set("items", "");
      BankA1.set("items", sampleMapsed.join("\n"));

    }
    
    else
    
    {
        sampleMaps = Sampler.getSampleMapList();
        BankA.set("items", "");
        BankA.set("items", sampleMaps.join("\n"));
		BankA1.set("items", "");
        BankA1.set("items", sampleMaps.join("\n"));
    }
    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);

const var ShapeLabel = Content.getComponent("ShapeLabel");



inline function onBankAControl(component, value)
{

  slot.loadFile("{XYZ::SampleMap}"  + component.getItemText());
//slot.loadFile("{XYZ::SampleMap}" + "{EXP::Expansion}" + component.getItemText());
//maps.setFile(sampleMaps[value-1]);


ShapeLabel.set("text",BankA.get("items").split("\n")[value-1].replace("EXP::","").replace("}").replace("em25").replace("{").replace("cs30").replace("K3").replace("FM").replace("misc").replace("sys101").replace("XP1").replace("XP2").replace("Basic"));


};


Content.getComponent("BankA").setControlCallback(onBankAControl);



const var ShapeLabel1 = Content.getComponent("ShapeLabel1");


inline function onBankA1Control(component, value)
{
  slot1.loadFile("{XYZ::SampleMap}"  + component.getItemText());
//slot.loadFile("{XYZ::SampleMap}" + "{EXP::Expansion}" + component.getItemText());
	//slot.setFile(maps[value-1]);


ShapeLabel1.set("text",BankA1.get("items").split("\n")[value-1].replace("EXP::","").replace("}").replace("em25").replace("{").replace("cs30").replace("K3").replace("FM").replace("misc").replace("sys101").replace("XP1").replace("XP2").replace("Basic"));
};

Content.getComponent("BankA1").setControlCallback(onBankA1Control);




const var PRESETS = Content.getComponent("PRESETS");

const var PRESETBUTTON = Content.getComponent("PRESETBUTTON");


inline function onPRESETBUTTONControl(component, value)
{
		PRESETS.showControl(value); 
        PRESETS.showControl(1-value);
};

Content.getComponent("PRESETBUTTON").setControlCallback(onPRESETBUTTONControl);



//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
 //  g.setFont("Montserrat", 16.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});

const var ulp = Content.getComponent("expansionad");


ulp.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/rhnqwh");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
});

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
 