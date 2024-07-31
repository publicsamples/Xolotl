namespace project
{

struct UserXF_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "UserXF";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "317.nT6K8C1dCzYB.HiysLBLKhS.fPyxjh30LdjUJHV.YxLODggPGrJryLB5BGOcEmfR+b.BsRwMDEHTd2bUw0xcdZjnPekuFzaLXAPdIqz6I5Pa0Qx5pn3E+KDm9Xs.2doTnFcAxK8v12iWj85.Tc73VqNHRLjBiigE7llg00fxVC7Hh7Ij1XTqljvmXLv80z9wrEA4mZMZBjalxPI+JwMx7LIVK4ebKB2GuYwZOdpZhiihvNmhyXA3FUXEPdmGk7O.4H81HDCH.I.PHSoAvN3JOfXf5j1kf4CnD0F0sCAirB.PfAKxQRuUKQweCAn3ViMD8Bf2VLHyfYer3eCMfMnxFc.WkgQL.Dn.yWvw2xM.nUmqfYohqOn+FWkiLfMyxr1rf.mYzWWQ3vogaQy.RhMxHWXwd7f0wAH5..K.djA";
	}
};
}

