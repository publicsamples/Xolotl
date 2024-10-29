
const var PRESETS = Content.getComponent("PRESETS");

const var PRESETBUTTON = Content.getComponent("PRESETBUTTON");


inline function onPRESETBUTTONControl(component, value)
{
//	PRESETS.showControl(value); 
      PRESETS.showControl(1-value);
};

Content.getComponent("PRESETBUTTON").setControlCallback(onPRESETBUTTONControl);

const var mod1 = Content.getComponent("mod1");

const var modB1 = Content.getComponent("modB1");

const var modtype1 = Content.getComponent("modtype1");


const var mod2 = Content.getComponent("mod2");

const var modB2 = Content.getComponent("modB2");

const var modtype2 = Content.getComponent("modtype2");



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



const var EveryLink = Content.getComponent("EveryLink");

EveryLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/hnwjrr");
  } 
 
});

const var QExpandedLink = Content.getComponent("QExpandedLink");

QExpandedLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://www.modularsamples.com/l/hnwjrr");
  } 

});

QExpandedLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://www.modularsamples.com/l/lybce");
  } 

});
const var ExpandedLink = Content.getComponent("ExpandedLink");

ExpandedLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://www.modularsamples.com/l/rhnqwh");
}
});


const var dp1 = Synth.getDisplayBufferSource("LFO1");

const var rb1 = dp1.getDisplayBuffer(0);


const var BUFFER_LENGTH = 16384;

const var properties = {
  "BufferLength": BUFFER_LENGTH,
  "NumChannels": 2
};


rb1.setRingBufferProperties(properties);


const var Waveform1 = Content.getComponent("Waveform1");


Waveform1.setTimerCallback(function()
{

	this.data.buffer = rb1.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform1.startTimer(30);

Waveform1.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xCC843E38);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});







