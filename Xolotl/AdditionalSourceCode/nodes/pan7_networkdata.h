namespace project
{

struct pan7_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan7";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "388.nT6K8ClMBT8B.X0z9PB.si9SC229lTqxfcvpLIXoBWIDXNbkz9IYw9++q0AMQLMsko.M.PC.1.Pk2vk2OrrpTx0XLXLCoTjTjz1PS+aXvNSNsJzzp4Om2G2SEw6bRxCb9sLzjRkUSHfeDw9RwrGtCzNMr0CNVy61rNV.sMRLH8pwv32GERuwbrhfs23n+Vq.ZxIxTefezhW35unZa4sqE75r.n4UkXuAxXXW10aI6LGmI8uEsZ2+ITp.o4mVD1uGRoPyHOJ.RjDdfvCHa.ZByd2OIZi2B3xbXYLQq50wJC1LmhrmOlIYhfkAjF8vt5rNxIIXKoTjztdyxBMSmo1E1w1CCYpD1tyAz.BPf.vTqc.TGZECfaDh9eX.beiwTZbYZrd6PHCqIqbX3AmnP1uYlNRB.PDTbZGqSXY.oIC.f6b4betBJf.Wv0Vpz1E6.jafguROVCCRsdOTQYvCa7mAfl5.m3Pp.QA6DictXYUDz.QW1PCKlnEq4f+Oyb2AsamfPHnGE.";
	}
};
}

