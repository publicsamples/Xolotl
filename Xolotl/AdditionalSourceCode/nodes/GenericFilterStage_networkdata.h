namespace project
{

struct GenericFilterStage_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "GenericFilterStage";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "3048.nT6K8CVL1UuW.n+Tj.QK.yJqCruRA0V1VIg3msFXZWDLv1JD6rNH6sqq0xbUcaaLb8bAdTanROJGbZo.uCf8.zO.sTk69o5QeNvF.tjX76rZpWK9snq70QwcjGadg.2b+59bWwAa01s45Eihrz0Uvzmaqkz0uxckHh0StlDyvixA+UKGXWIJVav164cwjeOXpFuqMS4Bq2L05ktCw8YybgYZJNB5Hwnmoc2b3kVhuAMyGxQwvylARTzB2Ey.s6qaGwLOa49.aonGp2tlRDzQDH9yeGES+nEm5GQw5CBR+Bkfnmk9YyB98rzr2cqEPT7SlZQH7MuQk.RT7qWJhhhVlZIQQuqED+XD89QTby5c+7Eh6ZgFWNtKw2CMqg+LmUhMK989EzODEinAOhhYfuZjeJB30ufL4RtjhKkL3OlFRAW1NlMTucRORfRI6WC4gCY.e17nXNszCGQjQYCoypwim8S9d6zZ.PIR50Jskrw.MGcCCvFDsoA2RFaJb.6tiQsLcjXjpezERQCfP1L9+t3YUFlTVgIovgWtKluR6rQ.hwLH5fwRBgLHHjvpBPVlr5GDU+Z84zo.PM3uoDQ.uAHVe1xVM.2vI24B1O.wJB9Y5B5HYLMq8cuSzKL4gifFRTbiu50.P72oSXBBQ49.sQDEEizLMhMxLrQ+1r43gkGuv68ftA2x8oLJexeXxaJwX843P8TPKgeaE4z0TAq12m0v7NRCIF8BuXh6dUkkp1.N983why+EUfvgXdP5y8WzRfgZsDc6inkDqbWFzQ9IXHiMZNeINkyJIkkiY4WVWYt2RQjZGQPr7eWtGj2CV+3.SmP9XJqrxjVNEJpLWHsyGQ2fBrHyBXvzTldWsssQJihB+b5Bo3yWJ5JtDqYnrc6x8XzTZnxmXXVfXAZnck.6DnrpoluBrV0DYcTvyEU3oolwP4ISahPYp3yTSMzLBbQvK6hCplUvIzDgr.BLh.mDrPY0S.zBMpHoCKYjGYP+uY+vkXSKLKJrp1xFc7rfzOVDu1L8hCX4xPadeHEdrDUXWXTSozphZJKSJ03yPSRFIREAeyTNN6V.U5L8BkfTpOXn2CpnlRexkxvtrpnlS2SViALLFrkKAeYhzidF4KQl2NSzRNx2OZuWEsTDjMhFqszboBBYZHTSYf0L6JaXsEtVPOokR2AEo5SlBO6rpmrobEyPEEiRrJIFk00UAxlxtb.ShElWYMMubrK+hxZdImlUXtUFlkr1goDV.cP+HKS1ADX2XdESKxYOMgMASR90nojev+htRLtP1zzovnttltjRIkCSShDc4ShdjlbISF91DBWyxlWTRLuSGQMQZEc8nd61vQ4b47zUbe5JiBKKaN4SyIPjUzMVvdgnoIskKkD4LzTWNB9I1UkzmRuJClDpRNzSglYfQ..fBJB.RHB.AiijEEHlB6gfHAgBAPAPBPwQAwvP.BDfA.A.B..Cv.DX.JiQYLjdZINHyy10yNru5msI+fNKEt3y3u8HCp5mty2M6pSBSfo2SkSO+noDIKTBLBSADjLAHh3OxnEd8e.+H.u9Q.pOLRbFZLCP0cl71DUoViaS1jYb81noXnZWUNov97fhTFZ8jWingbvNdAiyCLWossV2OYsVmclCxfbXEw1H+e8r1hczbcQzjXZT0fJ844YdzwYOG6kV.2Y22PzUiiN2dYJOjVtSScp6b4d0sFslTBA3DlaRDHO5MA6OHk5zCcptY0elQT9Enw1WfUItLrAjJq3mqVvTHRBJ7+xPxmpzLme9nt696QuPpRfbuWHnlHjICSwTukkQ8F4gHVbthZkot2x1f8CviyUbC1.qoVdIyKCqjwJnVgd1dJK5zRfrUlMojtMl9gH1d3H5XbEluSme1BqjfCnEWFWRhnu7aPXm7ZWDNAh6B9OtgD8IqNmFSP8O9vDfVNYN.ZDIzMhNPHCw6Dx4UsoUDtyhaCwsNZx8VkVI9K0HRxOzDLFHzWnhzAQI6PwIAkrkHzcjeDrB9JgEnMjJJD60lGx8y.VE.VFAgZy70LOWnCEdek5pMoCPwl4Pz0nwV13fkkEaFIZt2ewbWdQZIeWNKF35aTdkmrDOTvFMmknLUWuZBAEYR2e7qw8bo5XbSl4usEqwx.0EJ14j6B5T+DfKT1Nhr2d.goJD.KaY.QRBYVAt59RPKgcjvXQsB0wdjTthfKTQvhWR7clIDtiTFu8BSMMY.2JIKDGHM34gtvJoyGxubJj.SFMHfLES7lbUEGsCrAnmFHJwhahFkJeADjLFjTDJozAf72k6B.4DSaejSaDfYON.IRZDeZ3NjTYY.dlzm2O3qP3GRIcdc6hIEEgV3Vs2DZMCs3nUdpOHgxK5YRgGQWPcFAyUDmC5549irzEkE4PGxFaRF5WjCvSZNDjxSrtqTdPii+1RE1jHg.ccFuiLbEPwT2bDscPbpv6PW3lwMCzhveNQUXkfYCArrsGjgBj4CWHuR2idEBnHDyC66d3rCf4+O+fHIp61wQEYx8zkf4wcraB5bH0Gtv3xvWaAZcaljrvnR7iEhw6q210Z42Z++iSM7EZ4pOcqzCkHvQyUJLJXSGFn0TP1SBjk695JkF7HlmGj.0x89qNan+1zGvIDHiM+r5sUFYfQvj6BbFOVuornqAcp4PQUGtfEJiYCeCgH25LiS48+FLEHke.f6ZvRjGeJ+XcNhfJNGgpv+tlyhxHNlEipGRjdvTQUeGwgdSWzlSwvCXw5G4xFE.dBQlntAanensoR7ZdbGVX1jlj3OsI3HajDWvjHXwVE6eDVJveEgn4e.612I2HRVxilpC5J5LtFuRLNAXc9IM.6.At9DDen.jR4iLFPzzjzhFxfaEW4Hsi8W65bKQ5bCRCqbTI9PrqM5pVSnMXDiBlPuvv+Wvr1J1ct7MaI3qgmkOJI29SA+hGBFiDJhYnKD7u1G4P1NxlZ8crRqGX13Mmgy8AfIxdAn4JrEJ.0MTGz.StJUYh1KRaoAkggGjtP5hjiLrvc+9QL2yVaA44lLcAs7xppcxtA7gVCyqbWJwU5Oa0L.8ZVo8KAVuQwgS+RT59S0iT+9EdJQ3TQ0V2PHmySCig4zmwzvtgGfMwBYzezDOLLk92zOgX0BSzcY2HS3h4LPv8Pt7qdSB2uBHIonb.3hKM5Z9gbfjSlUsoVydrb2qmijWCOuhoBVCBE.r.Mbcp5q8fkHFFR.8.3WqQbocR2fC38HtbFHb7urX1cENB4ySAp2bePcQpOABR37IHu79dTwlMTP5SY7CZfVFA1cKeDfeeqh3wGkMs.ed8e4TdnhzrW8QVzE3FLVUVpfNhK35+nObeJQXobQj0hP879e.B.65ss6LTlDACsE1sR4x0o7AIMl2BFq0PIlDfba2WelFM84QGElvSTSovIQi8hMFNs2E0wZICHRPXz6BqkxguTdTVQUyIZwgTrhulwqUyxKVTdNWsPsqbv.XUpLW5P3lY5Fy7nMi2LoOKIuHkikMaiA7PGF5cOBxn4gYt9K2MH0XgcQShZoG5PsAYjKE2PumRu3WqozLCYxhmib.o+OmPR568b9a4iUXXCTSo5nfbWiMRGvdTYatNyHX2Bc0ooePstxHEgL7PNSF9qPWXf2geZ4qm1wnrSbI688+g0oR1EA+jingc7ntFH.aZmqBc.EmfxtrBOi9yKiaDOsUCS1Pw11sjRG4dhp+9wAJ2DjYDEyfTP4T8ZP39N+HbcQ5kdFPFXtJdv0+IVW7jAYmCdBxZFqYSxuXmhs56KVPyxXs9UHZVBP29xSDfDMTSDf2NsfO1cR5E9xY+VD0yfuZZ9aBLzEv01AOEM7vL70h+7CF2Ox8AnYVX16ovbPIK95bLiUNvgBbF.OQwtwXYPU+cmEU8JPFDIfdwpmHaFy5lGFNbHChpfITXCy.VqTKB3ZHstDAVZItUMoZkoI7ETGWChygse5PnEXuH3GgtbItNZjYP.N+RR1MXobHQFNOQ43EmN3wrZLOo2BvPZ4GLIKG5zDFlWGi1vjngzX7C+3AIyEWF9IfQ7U.8CH5fwIcgmx7Qe3h16sOCueE8MTZiIbMiHF7f6ZxG0pP6EA3e8";
	}
};
}

