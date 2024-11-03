namespace project
{

struct Fausted_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "Fausted";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "230.nT6K8Cle.TtA.HTSpHBPqwI.fiNIpIKOfVUyRaLb1UN..UyDmKwwvXiGSztizR+.O1aCrt.S0MHF+OxauMJqLMOKID+r9EwXen0s0JQBQ98woM9ZQLptDNxGczZdcfLCRlrLA+.FRB73QtM5xURH4WaLpNQH7WSYpDdeMsePUpf7rVYhXXqTE.jeWvkLuRhRhRJf7OXKxaiaPBIup8fLmHGjAB5bI9Z63ipHMPdEVfj2AFB06RvDf.kPC5Mf8Uwt9CAZIpftcBnLxXx7t05ZgVdfq1IvskGdLAB.vK9xVXAbAyOYTT.";
	}
};
}

