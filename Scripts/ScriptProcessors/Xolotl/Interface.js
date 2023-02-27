Content.makeFrontInterface(800, 720);
Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");


include("factory_waves.js");
include("exp_waves.js");


var Maps = [];

Maps.push(Basic);
Maps.push(ESQ1);
Maps.push(FM);
Maps.push(K3);
Maps.push(misc);
Maps.push(cs30);
Maps.push(em25);
Maps.push(sys101);
Maps.push(jx3p);

const var LoadExp = Content.getComponent("LoadExp");


inline function onLoadExpControl(component, value)
{
		Categories.showControl(value);        
		Categoriesexp.showControl(1-value);
		CategoriesB.showControl(value);        
				CategoriesexpB.showControl(1-value);
	
};

Content.getComponent("LoadExp").setControlCallback(onLoadExpControl);


var SMAPS = ["Basic", "ESQ1", "FM","K3", "misc"];


var SMAPSexp = ["Basic", "ESQ1", "FM","K3", "misc", "cs30", "em25", "sys101", "jx3p"];

var Cats = [];
Cats.push(SMAPS);

const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
                
const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);
const slot2 = harm.getAudioFile(2);
const slot3 = harm.getAudioFile(3);

const var HARMONIC = Synth.getChildSynth("HARMONIC");

const var SAMPLE = Content.getComponent("SAMPLE");


inline function onSAMPLEControl(component, value)
{
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

SAMPLE.setControlCallback(onSAMPLEControl);


const var SAMPLEb = Content.getComponent("SAMPLEb");


inline function onSAMPLEbControl(component, value)
{
	slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

SAMPLEb.setControlCallback(onSAMPLEbControl);

const var Categories = Content.getComponent("Categories");

Categories.set("items", SMAPS.join("\n"));

inline function onCategoriesControl(component, value)
{

	SAMPLE.set("items", [].join("\n")); 
	SAMPLE.set("items", Maps[value-1].join("\n"));
	SAMPLE.setValue(1);



};

Content.getComponent("Categories").setControlCallback(onCategoriesControl);



const var Categoriesexp = Content.getComponent("Categoriesexp");

Categoriesexp.set("items", SMAPSexp.join("\n"));


inline function onCategoriesexpControl(component, value)
{	SAMPLE.set("items", [].join("\n")); // remove the old list
	SAMPLE.set("items", Maps[value-1].join("\n"));
	SAMPLE.setValue(1);


};

Content.getComponent("Categoriesexp").setControlCallback(onCategoriesexpControl);



const var CategoriesB = Content.getComponent("CategoriesB");

CategoriesB.set("items", SMAPS.join("\n"));

inline function onCategoriesBControl(component, value)
{

	SAMPLEb.set("items", [].join("\n")); 
	SAMPLEb.set("items", Maps[value-1].join("\n"));
	SAMPLEb.setValue(1);



};

Content.getComponent("CategoriesB").setControlCallback(onCategoriesBControl);



const var CategoriesexpB = Content.getComponent("CategoriesexpB");

CategoriesexpB.set("items", SMAPSexp.join("\n"));


inline function onCategoriesexpBControl(component, value)
{	SAMPLEb.set("items", [].join("\n")); // remove the old list
	SAMPLEb.set("items", Maps[value-1].join("\n"));
	SAMPLEb.setValue(1);


};

Content.getComponent("CategoriesexpB").setControlCallback(onCategoriesexpBControl);







const var modtype1 = Content.getComponent("modtype1");
const var slidermod1 = Content.getComponent("slidermod1");
const var Table1 = Content.getComponent("Table1");

const var pmod = Synth.getModulator("pmod");
const var emod = Synth.getModulator("emod");
inline function onmodtype1Control(component, value)
{
	Table1.showControl(value); 
        slidermod1.showControl(1-value);
        pmod.setAttribute(pmod.gmodtype, 0);
        pmod.setAttribute(pmod.gmodtype,1-value);
};

Content.getComponent("modtype1").setControlCallback(onmodtype1Control);

const var modtype2 = Content.getComponent("modtype2");
const var slidermod2 = Content.getComponent("slidermod2");
const var Table2 = Content.getComponent("Table2");


inline function onmodtype2Control(component, value)
{
	Table2.showControl(value); 
        slidermod2.showControl(1-value);
        emod.setAttribute(emod.gmodtype, 0);
        emod.setAttribute(emod.gmodtype,1-value);
};

Content.getComponent("modtype2").setControlCallback(onmodtype2Control);

const var PRESETS = Content.getComponent("PRESETS");

const var PRESETBUTTON = Content.getComponent("PRESETBUTTON");


inline function onPRESETBUTTONControl(component, value)
{
		PRESETS.showControl(value); 
        PRESETS.showControl(1-value);
};

Content.getComponent("PRESETBUTTON").setControlCallback(onPRESETBUTTONControl);

const var mode = Content.getComponent("mode");

const var HARMONICSYNTH = Content.getComponent("HARMONICSYNTH");

const var FMSynth = Content.getComponent("FMSynth");


inline function onmodeControl(component, value)
{
		HARMONICSYNTH.showControl(value);         FMSynth.showControl(1-value);
	 HARMONIC.setAttribute(HARMONIC.synthmode, 0);
	 HARMONIC.setAttribute(HARMONIC.synthmode,1-value);
       
};

Content.getComponent("mode").setControlCallback(onmodeControl);


//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
    g.setFont("Montserrat", 16.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});

const var dsync = Content.getComponent("dsync");
const var dsmooth = Content.getComponent("dsmooth");
const var ddiv = Content.getComponent("ddiv");

const var ScriptFX1 = Synth.getEffect("Script FX1");


inline function ondsyncControl(component, value)
{
	ddiv.showControl(value);        
	 dsmooth.showControl(1-value);
	 ScriptFX1.setAttribute(ScriptFX1.sync, 0);
	 ScriptFX1.setAttribute(ScriptFX1.sync,1-value);
};

Content.getComponent("dsync").setControlCallback(ondsyncControl);

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
 