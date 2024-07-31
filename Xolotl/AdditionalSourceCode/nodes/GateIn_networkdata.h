namespace project
{

struct GateIn_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "GateIn";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "503.nT6K8CV+Dz1C.X7zAYB.sx1.zREqZI3UUHGQjIHYGjbiK.F997pYBd6R+qALaV.cRHnLEXC.0.fM.zE7XrqSoyVuWdBJd7GqSdOtwoY7XZUtY+JLrujzJlV2rRQh5bFwTp+5JzA73IJlGGgsJw8mDb8TZU59PX8FnU40mbwZESyai0LGl9C0ID8.LMCdCf2l8uelacLK1I9aatVmDF6pw9Toeo0qDb8r5kKBNgzR6uVPf8hKdEUVwvFshGe4iTpM6awBmjNepsIm7qOc4mZYUIletoWoYvdlV2TAbDHmGnHPP3ww.dZgJFxRLX0LLRpxqIKFi5FB13eDA5wA7gC3CDBedZd5C5lZx6jqpEXgBlXzalUafAZPlHhDIADTfPATC.j..PljcCvy5.ZM1CI2iOtBrKxGMB5vXh7Hqovy3nSzCtvxQZhSBfVPLSrwXRjCPwvnpX1CxAfbKwiaIAXPfLgYl.UaBT+AMiOhvcBvYfTHvOPB.q+knTP918PIFTCu.3hU3rxw2NCYKeb1+XrdpLy5g4zIX+3hK934i0jgJ.xueLzgthA..CIWCMfyTpzXEXfszA1FDSgyA60JLLvQ0zavLaqWvmFlAVqDCmgV0a4cVjg9j7TCmMD+36sEzG+7fFkHZJ73vecH55f38NF67.U5ATs.PUE";
	}
};
}

