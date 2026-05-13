Synth.deferCallbacks(true);
const var cmbPresets = Content.getComponent("cmbPresets");
cmbPresets.setControlCallback(oncmbPresetsControl);
var g_userPresetLoadInProgress = false;
var g_userPresetQueuedName = "";

inline function finishQueuedPresetLoad()
{
	Content.callAfterDelay(250, function()
	{
		g_presetRestoreBusy = false;
		g_userPresetLoadInProgress = false;
		syncSampleMenusAfterPresetLoad();

		if (g_userPresetQueuedName.length == 0)
			return;

		local nextPresetName = g_userPresetQueuedName;
		g_userPresetQueuedName = "";
		beginPresetLoad(nextPresetName);
	});
}

inline function beginPresetLoad(presetName)
{
	if (g_userPresetLoadInProgress)
	{
		g_userPresetQueuedName = presetName;
		return;
	}

	g_userPresetLoadInProgress = true;
	g_presetRestoreBusy = true;
	Engine.loadUserPreset(presetName);
	Console.print(presetName);
	finishQueuedPresetLoad();
}

inline function oncmbPresetsControl(component, value)
{
	if (!value)
		return;

	local presetList = Engine.getUserPresetList();
	if (value > presetList.length)
		return;

	local itemText = presetList[value - 1] + ".preset";
	beginPresetLoad(itemText);
}

populatePresetsMenu();

inline function populatePresetsMenu()
{
	cmbPresets.set("items", "");

	for (x in Engine.getUserPresetList())
	{
		local arr = x.split("/");			
		local item = "";
		
		for (i = 0; i < arr.length; i++)
		{
			item += arr[i];
			
			if (i < arr.length - 1)
				item += "::";
		}

		cmbPresets.addItem(item);
	}
}
