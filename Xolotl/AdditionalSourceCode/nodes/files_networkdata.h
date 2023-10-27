namespace project
{

struct files_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "files";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "361.nT6K8ClGBzuB.XlT7TBHKaa.8fRi7VDLgFbVR.vzGcCGiPhLqaQZ1dA.ZH3Joc8RLTlBv.PL.DC.8zU7msdhhUcpuxtJChAwfuSFcLZD+rZyA+Jqq2Ow4eOHpzetGXFqJggmUyDeNSuRVZ9HIVHOVfFE8q9Y0f.pLwJi9z0zwdhyWcQY7ypTtT1VWJnPWW0fhNz0S32XBVsZFnpS8TxzZGt52TTDtKV97hxfjXFhwLuphU0Nsu40XfNJcbJnzetIuiZCjcUsmsjN9KfppD9tYygvOxtua1V3.jdbfziFH3vQBLCzFMXFWMnuABONY9uEd.FiIw.HwKTDM6E3EQQKf.lADL21A.wATShgJHrGF.sYf3zBDFnguvzdwgO3vBXKgNggEQEuJSWXlkNCK5WrZnqYAUovzmOLCACWCt9b4D8uGTYxUyEL3l4YF5kC.GOF01sDMlAt07NbWGsfnJNCKFUFbtatHIq0d.";
	}
};
}

