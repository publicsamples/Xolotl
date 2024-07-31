namespace project
{

struct harmo_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "harmo";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "6613.nT6K8C5m7J..bBI.pgGVV7Bvvab.nn.S0YkcbKaxf0vVzfERR619+SEcZ1BxLyLk9+hKme6nv4B+zOYF3Qh6TrV.UEvRAngLVXoqjzECULfhy4+khDRt1DYiCl0DkMQaSljw4d9gJNfv.fxiqyzV1E6JCSEnK1E0sDqqyskY2xfccAAlhJO3Ifq73N4JY4wyiSK6NxHbVPGKEl1zF1M6Fmbogyc2rMHyJxkBqZR6AnaFEOCXRZpRjKKVB2yPbsl.egKcuqPucnlIP2syQ3jtTXvZw.VhN6NQgMsQw4CtBo6b9ls5ZiiBbZbNLkA6tQc1xI1ObMTy7i6xgxRAqoO3Gm6VMoQ5ZJ6hgqvgUYyj7H5ZYcowy1kjLqFqqoMKEGoqOfntxhr5nIxEV0ciqfgtD+CUbZaSTXZbDTZoqJB3zjtpXK7iyoQQK6tcqrYVLlbsIiq4GdbRWMMKVmE3rlrahfxtVS1MqqHN.OtMaVLcxt1hrbT4wckt.444FYcolxXcQx5howIiqgZn15ZRK6RAmyO73hlrt1f0g5BiIWTTJvcUkY2vP731viJONMjcYx1EjPkuaqv7oO6Iz+YO8YU1SpD9du+2ou+cuib1cSyVkQj1EWASmxWWepU5ajJzQHutRK4BFGzQcRoMHhgJk+K+GlPrnPIyHFLOPfXvCBirxcPBgv.0QI0KkBfHrRD9fSAXTDeX9p.THsjmfLFALPfffN9IeiPMpUDLBDzkRfnPlAuiQEoVB5XMIAPF.OHQcwgqQlKUhd+jUIM9++PHD5t6e88u2ChpKex2Go0oz826QYwvEEISmlFLJ.8QA9uMQh99eKuH9mZzgSo2u++++uhOhmGwyq3mvgvsH5SXYBcYj5xWOcZjhA7qsGfKr3ACoqJQrYambcYWRHYJaiBqI6lFmLcrQ2MXHbRTWcPcK4Bg2+hOT5ToOkypKgDRRJfY2Vggw6glzFKCgAf34AZylshq3REwPbKIiiFVD8lR84jB4Qd.Z1K0UBrDZHxtso.m2yJjVqu16mI2ULeQGQzjVUFSzQFtRO0tZ1MXrEc2cb9pQZLVqRJ9axsDaHQZWXI9NNPFqoMZT26FSXH3HTKeVxdyvhOOBmspx1.mS5dxDGrEoKkMRyhiHTTc9BJWqIKOqJbNMMnvob4AAk7EDg.T7MNWTlVbKUhxHiq0EUDSfJu+csJNfvU7OHHOgFlrqzDUlrKGlztYhngHKFeADSYjRmz5jJmxn7oP466PCMdDRFNBKMlkQITNqfFIDDPdvW5TW1xJ7cxT0HrkW9RW97mzkurktrViwXrkZ2Lliw36xXLFkQ5WcpO8MNQIXBu5Te1Uu5TuhgBQ8oC4fBsWaZ29loFys2dset2dW6ZSktpbMSPC9oCPxvbO6XGQ74P2+JDkXf9rqj.cgddrYJWvxHDNox4TVeMOMT4kJ7wLVqkHgv2O84KNgS37Midb9lv4OeSe18rJCzM74c2Pn2cGgd2cD5c2Qn2cGgd6dD5t6Q36tO8+8lz+AgzJ7AiwZrgQor8nbN8WNoz+MoUu5OHs5cCi0ucOJ6G7+qXB6dB64C9lO4.pzW1PX+Jv++CUjxO9S3OLXJNRfsHo.goIkA9hJN13bR70mCmS+A+1ixuhiSrPt.mX0tTSbbMIwQAPaQ2LbkgwB3eHDN+5j9vLNWTWZPMsIRDmyvQYinflGbEQvVVLYWKKKVFXIlSZGYrzdSevAkF+KVGMbvUvV77ZWIztFLSQPHafDIbgCy3SyHHvAOM2KlLUujIlU2L0l7b1h1cKZabtxP5pJir6F0zHb.nQVcxDgCKYZiMZLDzO5vm2MqD17rEHnPBYASc9tDqY8AjDA4EpMFzfNwMpYcfPmKZXvAWxLcvkP1.AdPYApKbPizlFTRhP78GHxVpDmOX85Pn7gc2zXK+O+SrOJt0TE9CpiXi0UJkglA...IB.iWF...QhHHhHQw8bmMELggEF.PX.CDCTLfw..BFHXPAAD..X....L..v..CFbnvhKHLfrMGapeNCmB8MH1n1cue9YlJl2jYiF2k9aNC036Rm8f5tueZFNC8aPrQ0cu67yLIluIYiV2kd2NC0w2kl8fzce+XFNG5avrQk6d+7mYRLuIxFstKc2umYdRJA2kN6f5tcuzLeF52gXip6d26mI4frEA6z3tz+WlgJ7+VyNntKWWNSGg9cX1n5t269YRGDWjrSS2k9elg53+VyNnvc4VkxzwPeGd1n1t2+9YREjdQrNMtK8+cFpiuaz8FJPuO4nhXS9yIeh9dAhmvapugjANAuNjuCS8+g3CUqJDkuOxoQjAjhaThHCv49DIyfDjlh7oMCRYeEwL3lVpUNpdZn2gnlqbseHPxBrLPjmcaHEQbeHbpjnDtOWjln76ZZCnHZlrtmSDOG9AHIxOJ1cyHhDGw8wnLrjUGEit0vIlMY5ZR3SKoGY.CSvpDjtYsxONUID4wOL+8ytN+a3lWvRRu0NZkg1Ief+SG.agbi1PkwkY3ujvKj5pLexzsRtVxjVH5AhKfYc.nvJ8oXB69uIsmHBOgxG.p7fnjfTXwISfvuntWPY.u2vqXXUu8IdI7MjgDt5x9vnIIIFehPzd6Lx4NvuRf1aoMdRrQkCvb.GfL9So6M5xhUkkAFyxCnp6fz4DN93IvCpRy1sVdjAq6f33NKoR7mxRXLIfGwwFO0uAaNRn.u.+4hiPOGfmlNH2GwvuZI9Gu.T3X1nisomjOURR.+yQu+QrUXHT8.uyk2vxbM24fXJL7cSEtMsCvCawVQTCQO+DSD0.u+kSvGJLroPJPE0Qk.pVYFgtOGeTqoApbvTDFprphfMmLXZmyYQUUtDrKOZcCDEEh+0.osyfhyOcMOx1n2yIG2MwKFK3MAg6A40FBeYD3RXiQL.sDFEmQcVNHxAx.ZEKuYJYQ4YBlTtNy2c87jmIZvwaplFkNzT8KNTPDRAjGe8brKQF2QPpXioyHOlBxHKngN2S3K1Qz3I5prUg9mACUHeffFpF2wc0wmOYiAVAyhVehZXWogCDlnYPzLtgWfZr37ZYNK5L4pBDaUXRr+uxvbaBfRBoTQn7Eb1Er6mnEfe7.NUAiE1HA7P3AVg8DIQ3k+euJCo1h3gES.x480mK2FbJB0AWTGNzasAPLXZbUqyxdYc7KhcSjDcYvZb4rqqbteZO8TahtunIbqU+6o3odvQwkBAvRqz1tU+F5CTz.g1yt8hTUuyanjCVgfXIoIx.4y2rMPk07YVCp.7QeHZbnRcsxhBqH8hN9WItDfA4Zundja1GAoO5Sx.fkMlgCcIvxMXL4gbfOu7qodPfwG2BIAbyHqdAi9ai.iroi.xXdx37ZgFmcEfn7g5AZA+ZuNz.XxlD5w4aFiiOWBtyjY3Q6YFGb1OxbXe2In2QNK4A0c6mhIGsZ+oPbjysZ0VOzO1zgRAqvy2BqLYbXIHCqfj1efeVYOCKzEQw++5yMZlByiw2rnqJpE3.ejwYwO8p3PnXua8ROXxHLo58xKmadoGHMCkurM14R+FVlNrPaAjtXhMJovYXSuaZOmdf3fx0yb3TQWK5WpOe2oInLOgYS5bi6qwiaxXwf9Yk1P1VBbXHfg.qv+o1Tj.iiaZBKdzxA7zOBd5APsEsIEj6k0.2VVyWu6D.BqYl3hy+8N4npgqt.npnvVsyBXfEb0BBBZk7SWbczn6xqJbsOJgPWrgFtW0QLRQseQOEJ9ud515ST0eR6P9ezd6dv2Pcmkabf.lVQlk30eI7NRiEkSwTm5Es1+S1otsWTUR0rpBfn2qIemvfkj4eGdox.lDZNbsp6zg6dI8esGqk.CB4lggBxAVpp9VjS3Vify+yU.E.UcGEzurl1Q.d7iYdiwFFPSab7W6vVI3PPVDwnmcvpJ39jIqqV5EREXc.F7yoB.UnWmQDRj6mBbGERxUdPRAW70yu7S2BW.BGFKQ2sIOrU44XBCUv+vleLoPn.PZXOAvh2I9Qx1oUe9MdtsTv0XWotcIi1zZ6TgiSnV8yS9Pckuneklr.M0njtS3PHGe5+9zC.zLetJVpPDdCLE6dfocUQS2Nu5XegsO3cMwRnnt.EWnMCoJ3n+RpGnzo9lzgl2i6SnUg3hRlZ6sT+n6aS0mvkcYLcfyeXoB6KQ+2BPUA+fopn.0Mrh3NqLzbyAcaPBYltyXURGG05Uq1N4C90mgD1qJmACASDVUgAUDmR9Q.hf7KUwFTgrFbHC2DGD20NYcMcOgQ8B9MWcQiZugOgpwrA+uYx47lbJoF2LCKGRqVyG4LLiGud+Ac1.EnfKcSdD7O4dEO7oG.w9X4rCqjAU.W.x3mI37GcEHRjYP2CMDTfAf2euYdGXEnwks2DWHfZixDnpr4mwgGR7mn6RQHHRBiPsONsT7XP55gRYsz+QLY6ZeFmAx4z9Alrl5sebbPSJ.hfOsMRzj9QLK9AFrvlTOnK.cr4FlcgkL8oZna4gHxpFtOjt7LY+BZv3RiLyA91HHg.WTqQpWnIdagm4MGFDHDF5wJGAcXoXQ8j+Ujv1BSwWmXXSlwhm1GwME4qRMbDc8rt4o4TC5S.yvSlLC4HujUCV0NhWdaz88E2Bg+KtAQYb3vsobyZP.NqZJ.KMYRzIitM27HmeUjmqUWjW.yQmpfZfBYGtuirC037PHXPpkbCeanV.UnaNibMKSEdicJ5.kh4+penICz9tL6C0dX2gNNVQMaIBnaIzX.QHFjPlcTU++fFJ07FIBSMIU28corKxWtno8tmVM.L5uDu.DjJL24fSf3a114T3CRNJKpH47Svi0qyvFbKyIzvI4ss9XOKqDLetpLdn6mbIIAE8Sux9y4U66I1cR83MazOYM04KlemoB2ljasm7j.Mh+9Da07QUzBxvspHp05zifb4xsDEyraV0f2MUWNhY2RdM6Y93z1+yxttTsIj3W9ER9yAEXlXmPPi4yFyC1AnmUiOUUfxblOl3weMjZyLeissY1OtdEv5LKN8qX4lHNyhex5YPhn4b8DmCEPXxR8Qoj7gbalel99.9x.YgaWAr.HfSwKM.nIW.ys..+Bx83sB6.2KIQNhN0gCEPvwlIWAXK4zT.tGIKEKJPdzqSg5eWAlcwj0frWq.sbf54xLX7sX9HMrmep535Ag3OZp+komg4.91eWKxzEddVXh4QxDY43HRSCi4yBWwM9bfdd2UTP8LHk1rUcZclNwYWP62DK.7g4JWb5hJVGT8LGbSr5LGe5XnWqB2vbisgUJjn566T4qKqAozrR05eRVCPphE9.aOEerblBQh2STT4VbpEEKilWDAVinVrg1TZi1mPEYA9bUA4ATlsU4r7y0DzK0QQDY2AWhIRLiHWxsClCfWRiREYHxjLO02pxVlj9KHJhbD+VS6O1pnKUrEldWZUQV9P8Ufk3ZtajZZjWy+mGQkJ4oBV0rndXpZ7tpJcK+ABsp3JTEUUWnQD3OpJgX9jcphYKoJUg7bw4mQUbIAkfVWeYxQqOj4U8ZRKL+eFdfgToeLdqM97d9p8F1qnZtEICYESASO3Kkl9PNZk1YIB.knI1QMnfhgnsm4CZPRaf9h8Omd12DVTXZ9fD+VN3eN5Zm0LZNM8ydYvITi2KG.oLpoRjRmvsJxOncfL8TBHby2EoTQ8d2yWVCEZ3fyva.IqwoLFI3MMluKGWAQc4+WsEhmCI05kewi5rYNYjBBqvoeykvBpRvBafXUofRo1EoZt5273tPLJyE.ZxMYeS.bQTaqiAF9P82R.1AfLDtVNvS4XXGT1HkRJYf2SCuHEvwMInu2IibINSlvk6mOkNtdAiPimjX9zbjKMuihNZwuFuPFI5rH3JtiBHjI3zKbVfP9N844eBOHg3x0QnO6UalYWlcOBUACH4uFE7gPjUjnWMY.pHEdS1Wfya8MvMsQzEZyo3g0giU4l89V8Xiw9cOwOeitS.Xzfp9N6eTuZNfDWIsFJH6lZ359v9U56HqjSnJ6QTCHzMAR1V6oeLt5AI5.gXATTUJ4oQPfMcHHaRP6fjJ0DXYEuTvfotVHm2ZI5B+fhdjg2nYScq9AaXbHtjQH7eZDH7xoegtImcIm6L4zn.gDZoj7PajkIRgnODfp+TNKKQFMnwJD7eEfUuHwyy5BQJt34Fqq4iBUlF94Wwv2U2s2HtFTrbTKNBqaCEp+0LoRxfAFKv25LOq9Of57WZjgU2i4eWO0owWR1cF8AzYO.XBLFRBzTGL.XFbiorkC+aL5x.nOqGmQ7hKhTRagO94K.OdA2fSQFIfc.rG.4AvR.lyF61IQXQmApzA.oFcoCSj7HEHf7AnUAeeigc25t6zALaXofIR8kWaJyGiHpNrqLmkJlHIpiUkRhL0AIPoHUJDPKLHk986mXU+98Srpe+9IV0ue+Lq52uulU862Wyp986qYU+980rp+cZVc2o4u6z72cZ9.Gd7tZ7wIk6256XnCGCz4BMbXTEbRD8U.pFwJOEBTePCEcxnIp2hkAsxMViM9VKfwsymwWtrky15BkDGI.dLGCojTm8RirBM4VV3sfmNpEkuVbL4hxMe1HDq8kcI+FeVY3sM8ZKd6yux.ZyEKDw23kaLuEtwuQvZE.A6mqkma+kO7TcuEY62F2Lp+nFcBaFL4Mtcr0l0m84PtRvCT413llHxV85FQDwDuVi3JymJ6FOXD5Wv2vVhG7Nd.J01ubwlPUPgDb.sH.4fRdTTPbxKMBUJPJgQ0T46LUL+z90x8alKXRTHqkpYhXEax3jPphcTwlp8kAbHGPCzz+Qdjb651dpsKydBDFlpsriE7TlPik82pjJkZ6kRuH6zeJFQFcRBK4KoDHkDRHhLUYBOTvIzEj8SiPMxh.VA7mMg.ogFOTzYYQOHQngFRXCHMb9XPxzCylAIio6wNtk2FOTHwWrimMqCXY3YSBXqHaY7c1wjUN0VmYxLd2iLGBxDpBNVVMDfB.PI.xpBg.F.JfTLmzhff8IFZPTHLL.L.v..b..LDvf..f.P.....Fig.TFwhLCVrwfTEtAnaBj91AQEhNy1iDSl6Xb6pVJDyRjbdpdv7f+vdCN5stc+4BJnSzAjGZqOpo7fNvLBMc+ITG733Uyz2NuoX0NEvlCohPXYphihdY0s32Vct8n3hvqA5pbYanDcRCEMlzn0cTSxzTrkRgD3e8JLnkttnPiB4JyzFd5r01vorIgEwI4ThGbDXQ7HhiYocvAdQG.sNc05HhpA8FAYAR8pdiNyE2Gr44E.ToWFqj9D+xYEmjX6RUTlB6B5E+NTZ5j8s7uHaLd.kff+HsLeHb.9m+TAAGRib0MvPFRXoes6n5PTk2v8aSokjXuB4AP80h.h3sZSj24uvpaYgiqwWvXe0x03647f1qlfnfSaI19bgFK54xEo6EfKud.7FAH3d5aAugRLf.IzsWz9RuXdJnGxoKilXHoCN2LVBHoSa5mrZTOuIXMBLUhk8SfOfBL.QSY+ijXLt.htFi+enMT781d3TxsGtpJYwx0f2nwe76uYji61rn0H1OSCIlTKs8coWuAqqIy+fsLO6lnCVj2Eh.4RZuo7VLGOTvklAQX8pdIAy9PxQpbKhNKc5HAsS5KXHuOxVJvSu7vbxyTyil.Mp5++ly76rm8xq2yQsJiRdAuZoMDgRyyRE4K4b2CXl4SDq+LbQDhhJKDcgShXMAHysxHeTglXItp1SBvy3lUncxSJWbgDpnx3.7o9O7d3U04eFD4GtJFMD2T.OfGKp+RyB.lHyUk86qERAGqU2zMxIf..LgeQ1lKLdj9Gu2HRlHh9hU1xoXbF.ySUu.x1NlaCnWJ0mLDzJJa4wKetZ11cZ6LPHoh5rmnPJXxuI4Iv0aokUzSpeZZjr+jygtmfTSGBWUjHkLtkX0PNZu5krovDzbnNtKk.xb7GB17vXmMSA5+tHvckthZ9ojPacvHaobQcCwyntshREo9S4qehjA1QxZruglh7lBSeYTxT4foXTgq2dJdLGf5b3SAjXoPRzbxF.yzBQBApD5sF8P3ynKXJY8YYdJzbsSE3ti7VHyAfefcxMaAjKYoP4LkOeQzhrTKgfOeq8HLgdPcf0Po8p102q+VuDgBq.aKOLvkTsFiE6VHGDstY.yHu5fHqPIVmLw0jofDczfLJNYjb06FMSifutiOPS3WhEDESdsqJ+zzSl4h3gYoey9G52oMYxaSanX3xdLarupR3niEcbcHf4PQNuzwYE5fWTC+P57Cv.NA7w79m6LNsZCokCoPazaXzMwpJOAADZ7hPRH0uRFBFVzfZ90QrhbpaWZqk1w4zIWlNOQrc.u1jnqJu2EbEi2ibGynHFZ2HbSkm5d3AQYCYZHEuuJQ3S4YFPhikzcJbqaaEPcQjmCtYmtNQRMUzLM2Je7wNxI9V7vzdMQ4NTIj5vql6TsMgJbWkrhnVet6wiaQ845LwJ5ii.W1.X5kVy.5cyaqqfhgGK0GToMdKVH.QHpHQ9+ISV3hObzF03WDptpTqYUR5ffWn+lj1l2dgn.SfXiE84srmGeRN+LfA5hmY8VVS1Z.DAJMMisAUHa9yooqjm353H.+hP7G9oZaQ2IYNu1hNgDtQH6LI9ZzxFxmDpwTEN5pJ8O7VL7VbZ0XY0.t+tNEno4wvkyAxg5u.+vcs7cq4HRaJZazzIXUHin2W6ZS+TFACIwsMRjWNpcolNjwvwk3lNo3cmqcozmkgvXS7diD3Em0taJmxLXrHtqWh7xQsq07gLFNtD2zIEu6bsKk9rLDFah2aj.u3r1cS4TlAiEwc8RjWNpcslOjwvwk3lNo3cmaW5ebFBiM46MR4Emt65bNyvwjtTw19tK8NLiAwDtpx18t69dLyABDWqv9d.qkbOA.";
	}
};
}

