Synth.deferCallbacks(true);



const var modB1 = Content.getComponent("modB1");

const var modB2 = Content.getComponent("modB2");

const var cBLaf = Content.createLocalLookAndFeel();


cBLaf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
 //  g.setFont("Montserrat", 16.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");
    
    
    });
    


const var Menus = [Content.getComponent("OscWave"),
                   Content.getComponent("OscWave1"),
                   Content.getComponent("SOURC7"),
                   Content.getComponent("SOURC6"),
                   Content.getComponent("SOURC8"),
                   Content.getComponent("SOURC19"),
                   Content.getComponent("SOURC18"),
                   Content.getComponent("SOURC3"),
                   Content.getComponent("SOURC5"),
                   Content.getComponent("ScriptComboBox8"),
                   Content.getComponent("ScriptComboBox9"),
                   Content.getComponent("ScriptComboBox11"),
                   Content.getComponent("ScriptComboBox10"),
                   Content.getComponent("ScriptComboBox3"),
                   Content.getComponent("ScriptComboBox1"),
                   Content.getComponent("ScriptComboBox4"),
                   Content.getComponent("ModShape"),
                   Content.getComponent("SOURC4"),
                   Content.getComponent("Stages"),
                   Content.getComponent("PITCH-MABEL34"),
                   Content.getComponent("ComboBox1"),
                   Content.getComponent("Categories"),
                   Content.getComponent("BankA"),
                                      Content.getComponent("SampleBank"),
                                      Content.getComponent("SampleA"),
                                      Content.getComponent("SOURC12"),
                                      Content.getComponent("SOURC11"),
                                      Content.getComponent("SOURC10"),
                                      Content.getComponent("SOURC9"),
                   Content.getComponent("ComboBox2"),
                   Content.getComponent("ComboBox3")];

for(s in Menus)
       s.setLocalLookAndFeel(cBLaf); 



const var af = Engine.createGlobalScriptLookAndFeel();
af.registerFunction("drawAudioWaveform", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
 //  g.setFont("Montserrat", 16.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");




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

	this.data.buffer = rb1.createPath(this.getLocalBounds(0), 
									 [0, BUFFER_LENGTH, 0, 1.0], 
									 0.0 
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


const var dp2 = Synth.getDisplayBufferSource("LFO2");

const var rb2 = dp2.getDisplayBuffer(0);

const var BUFFER_LENGTH2 = 16384;

const var properties2 = {
  "BufferLength": BUFFER_LENGTH2,
  "NumChannels": 2
};


rb2.setRingBufferProperties(properties);


const var Waveform2 = Content.getComponent("Waveform2");


Waveform2.setTimerCallback(function()
{

	this.data.buffer = rb2.createPath(this.getLocalBounds(0),
									 [0, BUFFER_LENGTH, 0, 1.0],
									 0.0
									 );
	this.repaint();
});

Waveform2.startTimer(30);

Waveform2.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xCC843E38);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


const var dp3 = Synth.getDisplayBufferSource("LFO3");

const var rb3 = dp3.getDisplayBuffer(0);

const var BUFFER_LENGTH3 = 16384;

const var properties3 = {
  "BufferLength": BUFFER_LENGTH3,
  "NumChannels": 2
};


rb3.setRingBufferProperties(properties);


const var Waveform3 = Content.getComponent("Waveform3");


Waveform3.setTimerCallback(function()
{

	this.data.buffer = rb3.createPath(this.getLocalBounds(0),
									 [0, BUFFER_LENGTH, 0, 1.0],
									 0.0
									 );
	this.repaint();
});

Waveform3.startTimer(30);

Waveform3.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xCC843E38);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

