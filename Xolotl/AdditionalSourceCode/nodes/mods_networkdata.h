namespace project
{

struct mods_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "mods";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "288.nT6K8C1CCTKB.HMipLBLqZa.S2KArrYso2EuzMV+FQoo4Gosse+dgAJvg+eLQCSJC3vwZsTAjpGXH49ZPRn42wmexT4L3jbbjHqeO+wxXpE+Nx+mEMUplFBLXUvpYYn4K4N+AyjWKJ4+NP6jvrEbrD2MYAXQjwlKBtKR3h1UXmrwhPSnFB4noCRJLlueMN9b1JflTh7yz6QFmPBMaH2Q0jowtPym2feGIgPdkUglHnvhlM7tCw1Ir.BbB.npEG.TFt5AHLc1SFyIgU54cx3FZR94XHFLqiYZDDw.LvcdQVxv8obEo.bWCWCmMxQHC6Y1xWfygM23jE.JLCnKAbvgLZQgchYtaLuhXyIH9BXtk2BAMWbDsXtkvwvPz4AdJf+S";
	}
};
}

