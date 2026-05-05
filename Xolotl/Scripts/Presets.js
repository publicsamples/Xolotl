Synth.deferCallbacks(true);
const var cmbPresets = Content.getComponent("cmbPresets");
cmbPresets.setControlCallback(oncmbPresetsControl);

inline function oncmbPresetsControl(component, value)
{
	if (!value)
		return;

	local itemText = Engine.getUserPresetList()[value - 1] + ".preset";
	
	Engine.loadUserPreset(itemText);
	Console.print(itemText);
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