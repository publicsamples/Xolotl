namespace project
{

struct pan8_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan8";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "388.nT6K8ClMBT8B.X0z9PB.si9SC229lTqxfcvpLIXoBWIDXNbE1QfoQn++2ICZhXZZKSAM.PC.1.Pk2vk2OrrpTx0XLXLCoTjTjz1PS+aXvNSNsJzzp4Om2G2SEw6bRxHN+VFZRoxpIDvOhXeIwrGtCzNMr0CNVy61rNV.sMRLH8pwv32GERuwbrhfs23n+Vq.ZxIxTefezhW35unZa4sqE75r.n4UkXuAxXXW10aI6LGmI8uEsZ2+ITp.o4mVD1uGRoPSDdT.DCR3QjGP1.zDl8teRzFuE3xbXYLQq50wpC1LmhrmOlIYhfkAjF8vt5rNxIIXKoTjztdyxBMSmo1E1w1CCYpD1tyAz.BPf.vTqc.TGZECfaDh9eX.beiwTZbYZrd6PHCqIqbX3AmnP1uYlNRB.PDTbZGqSXY.oIC.f6b4betBJf.Wv0Vpz1E6.jafguROVCCRsdOTQYvCa7mAfl5.m3Pp.QA6DictXYUDz.QW1PCKlnEq4f+Oyb2AsamfPHnGE.";
	}
};
}

