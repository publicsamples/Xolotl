namespace project
{

struct pb_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pb";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "399.nT6K8CVNCzBC.XTD4LB.Mq7mzBgHcG1S9gVJUhXQS8N0GHSyA.g++cxr8ovCk3yRxzB.u.fK.bwJx4ma+WaoDj3kekrw62Zc3IQ9poxDiXnPI9ZmlySvJXzmDeDwIwH7NyyTAXw2Gds6WrsqdxIivZGsrnDviilyuuRxzWpLvc4xzEJp4jb1RgLT.R7h0zVLaZ.CYaTNbnBLgqBC+URIHoPZ1ITymaRQhHxaX6DEBc9cdFJ6uWT9GKAqEDwheu1wyI8aV+aL7zPCe8h7MVkBRpBmLir7b+V65AMzATFHDISLVk8AQWnJ9XaKD7iEP.ctRTDng06DX.UgAfLib.F..xTtA.QGHJmbrMlGU.QNRTN7LEKle5ve.UPSCDc.a8b.4QFRz4SrjpXhwT3JjACd2MF9V3FrbvRqW0WRtfD3NhavQVtEk2FUC3mHmRwxGbTrfdB3Fgk3PLXUrgAxUxPYPksA.wrIUE10caFNt8F405Dc8afFcPXnZlFFM6vNxv8fsVXiFZ3YJxE+tNPEA3qB";
	}
};
}

