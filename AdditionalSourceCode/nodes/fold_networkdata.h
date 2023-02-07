namespace project
{

struct fold_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "fold";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "316.nT6K8CV+ATYB.XPz1LBLKhZ.rGa6RxlYynWwzRPDsVq58j4To2TpkBpFEYDsDP5zOvB.r.fK.j.+FwQP7MLMLMoB7Md0tcxajK3gVMdhpBiepXF6fGwXoD.7ObVv2fiqdaj.TToTwaDX6125f5zmJdRxaxE7Qa2JUEDdaoSPLtsszWigxAvO8zmJN9AoIDfBSPuUkj+6.kHo.+RUFT.AKjKvuTX5jG4zsxbjLv+vAA9JHVO2RwtmEjYcA7WG+usWHIwY1sRUwrjAEKS7HmHm2Md8f1VicfXiGTHugoIy1BRB7K362xfSCDBHvHHhX2QrABCiR0Kt2wffTRgnq7BVmkPKYi4rr.oCEpC.vcVNTUdHQlQ3BLPkqNtSfEScfSQrdM6eHuN1hczfdZmAtse7ltgvEFi.lzCejyHaF.";
	}
};
}

