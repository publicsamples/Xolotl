namespace project
{

struct pan3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "388.nT6K8ClMBT8B.X0z9PBDqi99R212J41gAyfUCnS.H96X4nIfa7frKA..Pogv04A0jx.M.PC.1.Pkuvk2OrrpTx0XLXrBoTjTjzxPS+aXvNSNsIzzp4Om2G2S8v6bRxGN+1EZRoxpoCv+gXeIwrGtCzNMrUCNVy61rMT.sLRLH8pwv32GDRuwbrhfs23n+Vq.ZxIxTefezhS35unZa4sqE75r.n4UkXuAxXXW10aI6LGmI8uEsZ2+ITp.o4mVD1uGRkPyHSOfTvANLvAjM.MgYu6mDswaA3xXXWDQq50wpHalSQ1yGyjLQvt.RidXWc1F4DDrkTJRZWuYQgloyT6B6X6ggLUBa24.z.BPf.vTqc.TGZECfaDh9eX.beiwTZbYZrd6PHCqIqbX3AmnP1uYlNRB.PDTbZGqSXY.oIC.f6b4betBJf.Wv0Vpz1E6.jafguROVCCRsdOTQYvCa7mAfl5.m3Pp.QA6DictXYUDz.QW1PCKlnEq4f+Oyb2AsamfPHnGE.";
	}
};
}

