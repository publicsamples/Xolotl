namespace project
{

struct moddy_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "moddy";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "273.nT6K8ClEAzCB.H1ivLBLKZU.EEkbDhMUchT+.DglNMQw7lOP2ObzfAVj93sZjnoS+72SdgcwmQd9.eOFVFpzZW0p3ugZMvdsX6rBDQ6A1ymqRa.U3GecvZoPvfkZkTKA56GnvPbsGq9kYCwQ14eUvpPekl4bn5kwVhjGZDwTfxFip+7jYpzTfPuDRcjwgPbbWbYydMIzq1E8rVJYXTi6Z7jHoX6Z7z8hrCnexjchhuYDVgE8M60n5UIUR4dMYrg7HF6As.nmwQB8NDePL6l.Z.BTBDAGj2vGIC14L0vA.pona5biYEHv9DnA6.gOXCB0.HfKr33Rg3PXQz8Pq5Y+fAvmcBby7rWA.m1ZFYtDYoxC";
	}
};
}

