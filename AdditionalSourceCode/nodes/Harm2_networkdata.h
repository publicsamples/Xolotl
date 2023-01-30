namespace project
{

struct Harm2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "Harm2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "2449.nT6K8C5NEG..svD.5mDfMvBvPxlG+26ZNVaMTkPO7Tg54swIpOsJ6xJqPHoTJGxEEE1lBUj2RplYPiuICbN.fCvs.TkxzfP2L0vX60bp5pCEtJl5fQaRGpX1PuvvbTdaChm4ELGks0fnpW7.h4gFQYABhw4hEMpJgYdMYfGpzlopJXLZGo4DhrvvvhBbPEZX4RjkLTJppJtnaXM0fppdMk5DUcgiLjYtwBTpJoLTjprzj4ptQB6pJsgSKhAhplflfs0n5jEpnZPv3..HNVzK5zzZpACy0b.whnb3L27YALp5TSFJVTp57hpJSi.PLMWyKerptxLs3ADiFUgADDyQwQwQUU4XQm.aaNfXYpTUZ17Qp5BGpjjnfwSVSGzh.wXfEGPrLXUwgKJFAD8l426NojenwVEzdXAkV.VHHJteUUkQS.NmDtAgdAICYlW3yT5RSB9QKhFEQuvTENVTUi5PgE8yTZiEnRULPgZU.NQdaQ7LYT0IELICLUhv9bUslRUL946Femi9yIiLGnYvsuccRecKEWy.dlbCwybhpNM.HVxiG1IM2cHKgQ1s5TIUUQjTUSK.IfIMyLANVZQzpv.HbQFUz3AVrnEQCxkJZfYhmIEnfMmllMvwTmo5CLVD0S0hVjKZP9TurnaprtPktvLyAtniPyAGpE+ICEsiFnVVzlfgMvo0t5jo0Z6l9+v+42c9+R4CP3KxLCgvMFgxu8NFis7kez4OW9xWxuyI48it24bvcc7y81ckNl2FxPl4sa1idr6tcueo+jt69+u+bw08+CeuG9jreDGuuj26gWGADSfuHds.tnbnYzhfwXtYWTxSzj.YkQ26fQJsAjtd8nCgNHyrS4aS3bRf3XxFMHrHpJsGXLN9PnzgfMnpZtpplvrNnziRoacT0XLxKt+y0vMBWn+ZH65OtOYjhTxRGK2dhOBCLJPg1CXK+36bOmyP1YHv.BOnhVqBZXgy+yvVhoRFZHgJZsG1dyNm+2DUtPgCvDQ99m66kiLTdfHP.IMo1nh4pJsASK.L2sG89a2a2bu+1c6d26uc++6M+b2v26aG2s7gvWyb2aLBkn4G28jW2R37i6dxycIb9wtuO2W2wtuO2WmY2Wn6qyP1cn6t2q6s6s66+Z22++8iw9e3+765+kw+4m6+2+426+6+4ue8+++7GKX2nJn3klYFXD...5fTb..FEzIcN4BnCHEVHjL.XHH.fH.H...H.D..f.fPPE...AQH.H.DDRDlw9fN.pcJNt3P+XZZEkqtjPXEbIOLnnr7ejzzsyDvm372s4NMW6uNqGVVEyby7eCUzLVE2HbPOzaBtvpRLJzwxQCNh6LCqs8hIfokqbOKX3q61h.viKxxtSqnNBjvH4sEqXqJfmAvn5.H+0a2hWy1+wLL.lqBMmm8Jj2FK2LtYqF6iYYzEc8H3t..CJo.SQSvsvZf8H3N1VwypCWiEQw1Rm3+sEBr5W6VgzSHrsLKfV1viGsWeIiVdPoe4i.j5D32xh.pYCZegU3.YH6C18iepPTSHzVvMft8pym1iuyHIOn1O7k.BcBbawP.J2qMuXmdPFV6A1Z+18J+54ZiI3rkC.DuW07WnBGHCwePs1Oeu1N045wDb1JfAzuW074N7Ej6qQj+.Y+hW.HxIrXqKGPkXxl6fm.yg.6Ay9EbAgjSXcqQCPm7jMVgmBjCQ1CF8KbAgDSXYqFflAwccv4FGN8Key4V2DLrEBnefe6cTtwgT+D2dl9Ogiak.jO3ucOkMNj6G8zgfmvqsfsAz5P+PaaUpcO3MGry94sA8UyT+Sv3VNBnuM3CbPNxoyHGpW+.2v6DLCNlf6VADPgaP6mvgmayJNDV8SbCpc5RztIXXqA.nwM7ANrmbJ4.GrqejavegyfiI3rkCAnxMnIf9nAtIWbnt6m4FVmdl9YBF1J..ctAevE6ImJC4P36G5FbmfIPwDb2Zf.T5FJ.EVGbSdwA61O0MnrxL0aBF2xw.ZcC9.Gjgb5Lxg52O1MD28Wew06YDhIvskA.T6F1.RrN3l7lC29su9HoI3ZK6.H2MP2A.VkwrbirhCl9U2VD7DbskAPOflyNOuCGt7qtMQxS38VW.8.Jw4zc7hCa+1mdDDmfap0E+wwmXiuZNuAoeocIgTlP2VQ.o.EtvmxgCg94NfQDSXYKFflE.tiGlcNb2uzcDIMgWaYAzCr3j64MGr8S+zhjlfqsN.xCVbxs7lC22ussoHYI3ZqKf9fcl7VVwAS+z81gflv6sr.5CVL6M4oAGBr2Avau+ZEnO5quh8t.4vd8uLfA40RkXPqScWiv73otZXZq4JyAlZKQ835zqZ06B8V8cy6bqR.r0z+HbNl48rL+ezPUj25u9ShGoNYJWI.iw9yQj5KTBpEZ5wEj5MEtj7HDKgV0yLSY3my6kuLVMeDCfzIW9Re9g6hyMYgrS1jtrrPp2BIZOt8dDSNEObs+1bf3juA23RX9Ex5wkpAWUxpWeWLlIQuRBMTnA4t4YfXa46G10mtIzgBiHmJ9bS91qHDbdHX3fXaDGiSUGamzkCZHwj8Vt6A7UcruPLxuCgYTuSJs+g6heyta6h+p7J3gHT1YrQyif3s.C3ailEIQcgsNEhLAE60rWDRYCSdBjAwXQQE.6rVUP3Gcz8lvnS1NIsbFwFh3eQ+gzsr5mJzE2jpaY..lrXXk0ihQIvK4YvjyLrOExiqxfHELapLEkfqffZHBBpmKKxKOl4WnitaCnZjnnyKNQixQYP7.4QYZ0BLLDpuSLmPNkHC9m5196tHkX1CUAJ.7kYXcfbMuMU7lFrHIURP5q7pH.YM8fVIbTA12dlttvmee+0gcx3ubRrAVwUAtdIjlSWJSDDIdGwEgGyfIWZqzKOQvy+A9Y5TNrP5sa35e2dIbj4euhixNRPnpr8rxqSxip9Lg.82Ak.e525iIUOZqp37gnZ1HZMDyxmGTTPIaueT2uE9kYk2MF2RLr4S.DV3JHThOY77tgoX.S7k87PEIQhAfBaKQVF47qsAIAzCh+5FWMey++Qskwil0A5kKILOQfCkzjPdbGeRucttfiU.cxOrEmdan6ixDX4MZ5qSU2U6zGAOMSLwd6lMP0HRn5FMMJAD8sJf8m6b.sgGir6Id5nKOGlqYjac8CR9dvaA97OPfEhMRChCHnpLNb9Cw98yqqOaZ6TG8bJGPLYZQAFdnm9YPoPlIlG5IK5XwDjHiGtwnFnt7OooDIxaV1DLamVUEAqo2XVpNhCV5iHCpp2sn1.v6NtaWR9VUO.";
	}
};
}

