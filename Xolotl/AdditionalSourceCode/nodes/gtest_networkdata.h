namespace project
{

struct gtest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "gtest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "339.nT6K8C1VBzjB.XYT4PBHKaa.WAKy8aCbwTo9DKvcrdGxejVJ1t2IDfA.HIXQYGDNSJkK.7B.t.vkoErcN+t2zVflWdVpC78SrDEZ1s2DUS1hsXtmGgck7i8aYYnYzCIzDC7s46IAtjm2pVP0L4mi3zTZx7ZX0vD9dlpxwPKKAG3MOy1Hic6MIglrUglsNFYMcXHcNGPBOVr0.M2zXn73Xyz872iOoc.1BgcWrcAPyEZlQX+cFFxRIGtqn3JNGBNcyEapYrcUeG03FpgxFPm2itNZEHgxNBmhyYnCaCFCZY7rKx7xz6RPh.QAGPLnGPh7DgEJf.GHZRncPcXAKVIIVK9DxT3q.VbYYSKTaN6QCxtYnHLXmhaStovFn.tcvPJLGee97M4klCmnwdnRcZZOGycR1IHTzwL8zJDdPlyOKegoEHiyiS3+TuC.Ns0LhykHKUd.";
	}
};
}

