namespace project
{

struct synctest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "synctest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "427.nT6K8CV3CzPC.Xmj8XB.saa.e5lrsrcM.SoBlh6.8.47A4sgyjWFkUo++ew9OB9vjTTlB.C.w.fL.TIIc3qeXrhIXUQe6YjL9U8FFq5tXmcUoI9wpv3aJ8P5O8uBNZxQVUCmEqBgLNw6c1dTo+RWh.V0woxgvnB66OHaPv36aqLWjRxJJmnMDwt7mkzXUctX0IlwpNeNarQInhxzTiAv4VNzvEXHpJ8mE16sxnXIWZpBRCmVEuOX9+ASicPQSo7BeT7ppmY0g3GR+8qVFnFbPEKUnjACEAVoKNhy0MIsuuheFBM1Hb4FJSJFhKRwNFsOrnzSA90CjygLvCztzZSYrzlLEjDngD0XJhHZQjZ2PA.vTXsCrg7EnBAnXLMqxpuBzdJoZXoZqYE1P0atliEhGY5P7YGnJhUIv9zWEkWxDIeG0Zs.5CCEgacQfXOhaOGhsoxRuSikaOs3MtULO.+OdShsaTiGqfiMa8LKziccgT6f188NB0FCnfQ7xHBvYxbE0dOaPj5IbgYqfg4kzN9ofXy3svRSpXnHPbGE6PogI5j.YKVNcntNP0A3qB";
	}
};
}

