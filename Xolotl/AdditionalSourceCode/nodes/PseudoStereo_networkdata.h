namespace project
{

struct PseudoStereo_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "PseudoStereo";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "111.nT6K8CRt0L..hVzDX.XhJfX+zEFtneBmDjtrcaE4JFIWa5PR9neOCU7Xu1DGrB.aPbagJz.8sEtsDUDbVs3YglKBKPN+TZty40uGxzwMNk.mIX3NiPSE6MAB..yDAvPPnBfovxHMDNBKBrXEdZUT";
	}
};
}

