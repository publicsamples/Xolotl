namespace project
{

struct pan4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "388.nT6K8ClMBT8B.X0z9PBDqi9Yw11xlTyyfYvpAzI.D+crbzDfEdmLoI..PgkjabgwRx.M.PC.1.Pkyvk2OrrpTx03KX7BoTjTjzxPS+aXvFSNsIzzp4+l2G2S44ctH4Cme6BMmPY07A36I1VBwrGtCztLrkCNNy6zrMT.sLRLH8pwv32mDRuwarhfs23n+Vq.ZtIxTefezhU35snZa4sqE73r.n4EkXqAxWXW10WI6LGiI8uEsZ2eISn.o4mVD1uGRkPSHSE7v.Db.wwiM.MgYu6kDowaA3xZXWDQq50wpC1LmhbmOlEYhfcAjF8vt3rMxIH3JoTjztdqhBMSmo1E1wtCCYpD1tyAz.BPf.vTqc.TGZECfaDh9eX.beiwTZbYZrd6PHCqIqbX3AmnP1uYlNRB.PDTbZGqSXY.oIC.f6b4betBJf.Wv0Vpz1E6.jafguROVCCRsdOTQYvCa7mAfl5.m3Pp.QA6DictXYUDz.QW1PCKlnEq4f+Oyb2AsamfPHnGE.";
	}
};
}

