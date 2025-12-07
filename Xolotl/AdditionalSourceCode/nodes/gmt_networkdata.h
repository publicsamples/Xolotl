namespace project
{

struct gmt_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "gmt";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "496.nT6K8CFDETyC.Xh0GQB.wUONiQDswaTLsxaCQkN0wWt8G5sG7t4gw+tp4NXsIDJnRRAO.vC.AA.eU4n9ynemzp9.Gec8osJ8V4Rr332hFw4XGNciimzns9VvutJNoWYaR5DEpT9.ewlzsiknH.GmQkR49QBlW8IleKzKNtxaMov4Xa8kHQChMWlYiRNGy90kp7xLLZD.3b7UtRutTFqrzlfEGyV.bOlGgcrdq0y1fHPEJPPzqYdLra1plulFeUhd.HGZvgGFfvHnGmGOfPJeFT7K58bd77bdHH.rYXXHMyaiHU1eodp3PzjtEyHj1wL2OvLagPQM3jvMZm+c.lGT5yIQJq8qn0o1.HXjySDTzSA8Up4RdotgosnXWHcLnxIyn0ul5lk+5S7XlFudSAZLIULSvL.FDV.qHX.b..H5HafNjFMfEPXBvICdiqBND.0B0Bd.MKsorekEV0ZgVvwrhPYK8PAL0VA7S+XxBaLJnawCwfKmR2QLphxPODeh2dy2KSGG5xQNLQ7whtFDOXsEq1vhKxkbAu.4URspuGjNfaKAtjf5ZrajMv5PFyOTw.0AOhCLE.jgzCASw26f0Zr2CTPsq.Hyq3fwBZbORwqaC6WX1g69CRnvsVJLS1vZVme9h0+PTY81Al10ATxAR6ABpA";
	}
};
}

