
const var PRESETS = Content.getComponent("PRESETS");

const var PRESETBUTTON = Content.getComponent("PRESETBUTTON");


inline function onPRESETBUTTONControl(component, value)
{
		PRESETS.showControl(value); 
        PRESETS.showControl(1-value);
};

Content.getComponent("PRESETBUTTON").setControlCallback(onPRESETBUTTONControl);

const var mod1 = Content.getComponent("mod1");

const var modB1 = Content.getComponent("modB1");

const var modtype1 = Content.getComponent("modtype1");

const var SAMPLELOADING = Content.getComponent("SAMPLELOADING");

const var importer = Content.getComponent("importer");


inline function onSAMPLELOADINGControl(component, value)
{
		importer.showControl(value); 
        importer.showControl(1-value);
};

Content.getComponent("SAMPLELOADING").setControlCallback(onSAMPLELOADINGControl);


inline function onmodtype1Control(component, value)
{
	HARMONIC.setAttribute(HARMONIC.modslotsel1, value);
	modB1.showControl(value); 
        modB1.showControl(1-value);
      
};

Content.getComponent("modtype1").setControlCallback(onmodtype1Control);

const var mod2 = Content.getComponent("mod2");

const var modB2 = Content.getComponent("modB2");

const var modtype2 = Content.getComponent("modtype2");


inline function onmodtype2Control(component, value)
{
	
HARMONIC.setAttribute(HARMONIC.modslotsel2, value);
	modB2.showControl(value); 
    modB2.showControl(1-value);
};

Content.getComponent("modtype2").setControlCallback(onmodtype2Control);

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


