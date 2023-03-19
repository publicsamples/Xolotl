const var Sampler1 = Synth.getSampler("Sampler1");
reg sound;
reg totalSamples = 0;
reg isCustomMap = false;
Engine.getOS();
Console.print(Engine.getOS());

const var SampleName = Content.getComponent("SampleName");
const var Save = Content.getComponent("Save");



function savexml(file)
{
//   Sampler1.saveCurrentSampleMap(file);
}

var shouldLoad = true;

//FileSystem.browse(FileSystem.Expansions, true, "*.xml", function(f));

inline function onSaveControl(component, value)
 {
     if(Engine.getOS() == "OSX")
     {
Sampler1.saveCurrentSampleMap("~/Desktop/" + SampleName.getValue());
     }
       if(Engine.getOS() == "WIN")
     {
Sampler1.saveCurrentSampleMap("~/Library/Application Support/modularsamples/Xolotl/Expansions/User/SampleMaps/" + SampleName.getValue());
     }
 };


Content.getComponent("Save").setControlCallback(onSaveControl);




//! "Page" Logic
// Nothing special, it just shows / hides certain elements...

const var editButtons = [Content.getComponent("EditLoop"),
                         Content.getComponent("EditRange"),
                         Content.getComponent("ShowDropper")];

const var EDIT_LOOP = 0;
const var EDIT_RANGE = 1;
const var SHOW_DROPPER = 2;

const var AudioWaveform1 = Content.getComponent("AudioWaveform1");
const var SampleDropper = Content.getComponent("SampleDropper");
const var LoopPanel = Content.getComponent("LoopPanel");


inline function setEditMode(editMode)
{
	AudioWaveform1.set("enableRange", editMode == EDIT_RANGE);
	LoopPanel.set("visible", editMode == EDIT_LOOP);
	SampleDropper.set("visible", editMode == SHOW_DROPPER);
}

inline function setEditModeCallback(component, value)
{
	if(value)
		setEditMode(editButtons.indexOf(component));
}

for(b in editButtons)
	b.setControlCallback(setEditModeCallback);


inline function onSampleMapLoaderControl(component, value)
{
	if(value > 0)
	{
		local id = Sampler.getSampleMapList()[value - 1];
		Sampler1.loadSampleMap(id);
	}
};


//! Non persistent UI elements
//  These UI controls do not store any data, but will read / write
//  to the sample map directly.


inline function onLoopControl(component, value)
{
	sound.set(Sampler1.LoopEnabled, value);
	
	// Make sure the loop end is set to the sample end when you
	// enable the loop the first time
	if(sound.get(Sampler.LoopEnd) == 0)
		sound.set(Sampler.LoopEnd, sound.getRange(Sampler.LoopEnd)[1]);
	
	// update the loop point panel
	LoopPointDragger.updateLoopPoints();
	
	// write the loop points back into the base64 string
	SampleLoadSave.storeSampleMapData();
};

Content.getComponent("Loop").setControlCallback(onLoopControl);

inline function onXFadeControl(component, value)
{
	// the slider is 0...1 so we can use the available crossfade range length
	// to figure out how big of a crossfade we want
	local newValue = parseInt(sound.getRange(Sampler.LoopXFade)[1] * value);
	sound.set(Sampler.LoopXFade, newValue);
	
	LoopPointDragger.updateLoopPoints();
	SampleLoadSave.storeSampleMapData();
};

Content.getComponent("XFade").setControlCallback(onXFadeControl);


/** This namespace will handle the loading / saving of the custom
	sample map content. 
*/
namespace SampleLoadSave
{
// We'll store the samplemap as base64 into the drop panel
SampleDropper.set("saveInPreset", true);

// This function will write the current samplemap as base64 string
// into the sample dropper panel and will be called whenever a sample
// property changes
inline function storeSampleMapData()
{
	local v =
	{
		"isCustom": isCustomMap,
		"value": ""
	};

	if(isCustomMap)
	{
		if(isDefined(sound))
			v.value = Sampler1.getSampleMapAsBase64();
	}
	else
		v.value = Sampler1.getCurrentSampleMapId();
		
	SampleDropper.setValue(v);
}

/** This function will set the sampleproperty and write it back
	to the sample map base 64 string. Use this function whenever you
	change a property in order to ensure that it will be saved in the 
	user preset
*/

inline function onSampleDropperControl(component, value)
{
	// Check if it's an object that has a `value` key
	if(isDefined(value.value))
	{
		if(!value.isCustom)
		{
			// if the string is empty, we'll clear the map
			// otherwise we load it as ID

			if(value.value.length == 0)
				Sampler1.clearSampleMap();
			else
				Sampler1.loadSampleMap(value.value);
		}
		else
			Sampler1.loadSampleMapFromBase64(value.value);
	}
};

Content.getComponent("SampleDropper").setControlCallback(onSampleDropperControl);

// This function will be called whenever a samplemap is loaded (at the end of a preloading task)
inline function initAfterSampleLoad()
{
	local id = Sampler1.getCurrentSampleMapId();
	
	isCustomMap = id == "CustomJSON";
	

		
	// fetch the first sound
	sound = Sampler1.createSelection(".*")[0];
	totalSamples = 0;
	
	// if the sample map is empty, clear everything and abort.
	if(!isDefined(sound))
	{
		LoopPointDragger.updateLoopPoints();
		storeSampleMapData();
		return;
	}
	
	// We need this number for the loop point dragger.
	totalSamples = sound.getRange(Sampler.SampleEnd)[1];
	
	local xf = sound.get(Sampler.LoopXFade);
	local xfr = sound.getRange(Sampler.LoopXFade)[1];
	
	// setup the non persistent UI controls
	local fadeValue = xfr > 0 ? xf / xfr : 0;
	Content.getComponent("XFade").setValue(fadeValue);
	Content.getComponent("Loop").setValue(sound.get(Sampler.LoopEnabled));
	
	LoopPointDragger.updateLoopPoints();
	storeSampleMapData();
}

/** This function will load the given file as new samplemap. */
inline function loadSample(file)
{
	// the parseSampleFile method will try to 
	// read the metadata (loop points) from the audio file
	// and create a relative reference if the sample's in
	// the sample folder
	local s = [Sampler1.parseSampleFile(file)];
	
	Sampler1.loadSampleMapFromJSON(s);
}

/** We'll mimic the behaviour of the audio waveform here... */
SampleDropper.setMouseCallback(function(event)
{
	// Clear the sample on double click
	if(event.doubleClick)
	{
		Sampler1.clearSampleMap();
		return;
	}
	
	this.data.hover = event.hover;

	// Show a file browser on right click
	if(event.rightClick && event.clicked)
		FileSystem.browse(FileSystem.Samples, false, "*.wav", loadSample);
		
	this.repaint();
});

SampleDropper.setLoadingCallback(function(isPreloading)
{
	 if(!isPreloading)
	 {
		  // whenever this is executed, we'll store the current samplemap data 
		  // back into the sample dropper's value and update all non persistent
		  // controls
		  initAfterSampleLoad();
	 }
});

SampleDropper.setFileDropCallback("Drop & Hover", "*.wav", function(obj)
{
	this.data.hover = obj.hover;

	if(obj.drop)
		loadSample(FileSystem.fromAbsolutePath(obj.fileName));
		
	this.repaint();
});

SampleDropper.setPaintRoutine(function(g)
{
	g.fillAll(0xDD444444);
	g.setColour(Colours.withAlpha(Colours.white, this.data.hover ? 0.8 : 0.4));
	g.drawAlignedText("Drop File or right click to load sample", this.getLocalBounds(0), "centred");
	
});
}


