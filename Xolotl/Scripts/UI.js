inline function onOscWaveControl(component, value)
{
	Engine.allNotesOff();


	if(value == 1)
	{	 
	    HARMONIC.setAttribute(HARMONIC.VoiceMode, 1);
	    OSC.showControl(1);
	    MULTI.showControl(0);
	     USER.showControl(0);
	  
	   
	}
	
		if(value == 2)
	{
		HARMONIC.setAttribute(HARMONIC.VoiceMode, 3);
		    OSC.showControl(0);
	           MULTI.showControl(0);
	           USER.showControl(1);
	          

	}
	
			if(value == 3)
		{
			HARMONIC.setAttribute(HARMONIC.VoiceMode, 2);
			OSC.showControl(0);
			MULTI.showControl(1);
			USER.showControl(0);
		     
	
		}
		
																
};

Content.getComponent("OscWave").setControlCallback(onOscWaveControl);


