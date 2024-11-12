namespace project
{

struct ga_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "ga";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "131.nT6K8ChlUO..hgvFa.WZUzXKGM2RMNB4lb5z7BPFPofppVHpsDc5G7eXuwUQak8eHfbUz0UnS9iEB0klB+4TjVp2mSiOtgDjGIprlliM8fQ98fWYdURkTn.4erC1ahO.cx2bOFYoIgYLbRBgqJPF4Mf3jeQyLwcEC.PSHfwSNDpUfiB";
	}
};
}

