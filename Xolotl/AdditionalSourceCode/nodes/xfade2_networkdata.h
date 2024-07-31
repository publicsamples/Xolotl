namespace project
{

struct xfade2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "xfade2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "4605.nT6K8C5FeE..M9H.J.G3TzBrPVwM3UfTZtdobzukpUA6bFL5EH8gm7OC2dk6Txnd+fxtip5C71745OLPhLPSALU.8DP1FGlEQQuGsiZQHcQ3gEciiUDIXp2GpZVfknkcOUA6ol.SMe4cUy3fp8.1xshAg+8lNfoYq1o4MgY17DV58t0NMP1JXKWYVOWZzZFGOQS4C1lKK1slACw1G5kmHwRKDGG61mZGCw.vtv9vwp8hhv7gg3RqYVLE9MkpPUoeuc32NDuqIzgv49Pz6ZBVUMMaESD8dbc0NW5FMKVGMCzkMy0EELGJaCqKCTF9R2.dx60czO1NPTvT5PnYpfxnangkQJ5II5Q+rgIydif9Yi4WU2gkswwVhHvk8CeQRz6wEg6V6penWZFfX8bU43nagbvSCi5wByspgQ6zrVb.hdd5nYD5Z6rnPPJ5UurTHJpZoUyvzngwkVciCjl2DKI5kgQ2vQkvCyDSI5oYw3t0MdMKI5YgoY8rEJylAH1rLJdd8h1QHbknmESfiddbsfzUoPPnNLKaVcC9hDw9myH.hFJGfM8QU72Tw3pIdQ0GNzQCLz1b0UArSklKBkACO+lqPeFxxfVEEUH9XvQnKBkAFFrQFxz.Fnj2fDto2LkKbYbqWXYZL.W8xgkXBF4QjSdR7fV2dVR6yWNkvYjwDRGZXbTOY7rXcTMVfrclxKjkVEDGpWHDmTS36tLBmppbGjpGZr3SfSt1NZVFlEmsojlZKseocOhtdof3P6bjWhK6GuiENGayB1FKIokDfGKM5kC1RDI+4rzGrMczv7zYsezvSbIx6qKJSgyA3Lp0FbSHhiDsze7EN3XleOMY3IuGjk7ADErHDV2stYuerZ5db5vKHalsB.7dULniJj9E59fAPPhwGXljrEhtpWWUN97.tM2JeIp.sDRROVcXfvwgitNrbLAjjOtZGMB7jtKsSyl0dA+PEIcCXonWH0KsIDE83t0N5.jCBQi7e++X6ODlY8vUud1vO.iw+iwXDFgSIODRQU0v3rU7RPn6OD9Mzkd+te0r+TnzEvmngTU5BL0TbHdI5pbUMXHdnZ5a3DRQMQ4tCGvTkIQZXzNUNnMtxyXAfXufuzU5ZVmN1NNcf1zv19DQBlbIIkAfabtpbLBhLqLYNAHBeuqvwIYrJDNQzgvRQeOQD9R93+wnO6GjtpWYVH.YC3gkMiCNyPv5Hpg.FX1kQTRtre3jQ4vl0I18DUEbVU8S8zWQxiWJGLtnoJrr6HXHU2f5Oohd+dG6tiQLQ9.8s1oC1sqpQ7iKnJpbzZVUC1BGHMrEpEk2UlUB7j5EQ3gEsqihO5PYOkMkjppa1xDKbjHIL0MaV8CsJ2kmHW5Etj2ixJW1WfvtLPzNpVvR7fLx7PEUvW5OZYwwREDdAQgZmsoH+DYH530.4buqJGHMKvxH78dpsTMojQ36ckNbDW1L0N2Jj7qrozQbovypZzbfzXUs30dzQwjudYyX63hHcVOZpZuOvrfmrbCEwKjgkfSdb27Y0MXNj50y5p4AlJixgMKBbENTlMC2e8GShtbB1SXLBO9smN36RluOewgTc7cONfKMmuPMaMLZFInLBeuqlTxOBquId0sPa9zMED9Oz89qbeRI8nCKv+Tvjm+H7mt+SSazra8CL9GBgOjB9e+Rd4+tbx83G+Hs+OEu+XU+UU+OM0U7u6FN0FXNi3+++++++GqpnnlplZ.7+7qjRWx84zqplUPWBUjZ1TxWRQ0SAX5P2onlSpo2tjzkZ+mbJJIUGIJm8rY2iwpJYrJdf1aWB5Sb2c2c2cHDBkQgpg53V5koPCMx...j.BvzkA.BLnvAjFUTVvUZGLJ3PgFGDbXfB.OJn.fAB.FT.fiABFD....T.XvAfBgChgnCmq2pOXGRUQGklgvEXxG+MJyZjbXbeA.fx9uwwjcg0Mu5YLF2B3.NGmwKtpwgJ.NH4rN7MQmtNZ7Gw7YNSGiLbz97w9EMjfDSDhLhPXljMCiwFqEvLcO84WZ3eZCc2JSH6EVulC7OIhq4YPFPz2QCXCDe4CVnSQvZL8903j5yJmbjandtvUBGsc9lUxiNWBYxzjdDNM0KBsD2CLbtDDiL1rIzEnYG.8z1GtgH1T4sypXZ1EwxhpPZwbDuAvjM4hooUZkPuLYggtwSfNyxnCMJ.pLUQOCArY8mJ5gfdGHSNCYbn6wx7jwUezMFPGN7znntlZfFsOM5sVSsHR.FYRlsok7.EVPWA6bRzXs2ShzTfu0EE0FGCiJjXwYa4v+5qVU8PmsHfN1LMkyLXft7WJ5AncqclD.fdEW0.mPizZpHUXBvTuEBztfvFODL8owWxEeXj3ZNBSSAfayG0yPL55ZCgtG7wVcWft2vBPIdsuwNRsmlyG0ZMM7Kf5xg1cRLIjkzVk+cD+ovHGbGo.j40cwGX5o6t9M9DPfqVEkPLpOUWz9VZ4pKPsG8bW9tuS41QigWORMm3GG2LRFeXki6mWNtEdYBt2eROztGdVJPuesoS.WCjC7vMX3vO1PAfCu+zC5wOxE8uPvGCfACmJiWclMLLNJRcRs.RaOYFvfoNfJ3JWchvSIZGNHr5Yg0ryvJGZUy5YbK.RMUVRnDI2pXJy3.icCC5Nz.Ou00Z8B6F1WS0FrXVCRdX+AcTtMPPh+KFNhIkckUyTwDDszrhO67SvaS2Bqu+vRS5oCnT7Uz2nBUGzyXGFnybzO4X+DqWCQtRxn5k05BX101WLFk5VGYXp2eKxXXVOohgMLnHWwgAutH5zMTdLJAkPmrkKbLnJbsg7fN.5j1nwAb9khBCGXiOqVT7TJDIx38dQvKRDYJPUwz0ymCETDDMLc89IKiZgLt6hMF7rsWxgdToZYAgFWOXW6Is4hFeIx6eik35ieHyqS+NIDeyTm+phdyrqRqX1B4u2Jdz92E96tiBG6OjmFnCFFj7IKKyACJ+kf1IJnicd5B67j+gww4nZvqXZ3GBeiCqJBNbALU+NM1rwUXmFQk53X5KPfmzzBGD11vSxkcclFiQUF+CTkowwuhMdtcFEikYBKDSyksQnTJkl4yCko+d2E5ZSbTLxLHc.yaHxFmMH7VknOAxRQlVqAqm5VTxru9jIthaAr+ic.hcKtDFl1C4hwLfsetDN1mzOQkw23EsWILsYpbdgDBIAQ.HYxf3WFNFgni.y.KuP6ILxxM3NgbVkVyHD3bKn+OjaL3bsrenW7lu41fLxRJGmVKBVaOiIXZ9mtxUcNHobBfZNaPSSCAP0J6j8XLqUpRqacAjSSbtTyATUQqNo4bmmQq57r4Hw52l4nbUwre1TauXnateyS.apjMvwhetEJLAvpYwooTzx9yFEBK00lOCLlc0qZHWq236A5txtOYC7ayuWIiQKbXdOaVJa8bZpWoGCjrUpWPGu1WgAcyBey4rWDfNOeEp1A4BFpM+oEiwsVh4z+3mafAFTUKLOhKf.C04PgSjjFzGj0tDNmJJ.M9ZFczuWncMX3jvN4Y.JNKs.cY0aVjP5EtcooC2SvEZBEmNYjpIFi7WDwdjhIbEpRF1DNQ748Lc6uXCxTeHsGMlTzcLUkh6EjfHIIxfjQJHtRvLNH6IGp5zS5PHnT5P5E2N4HQrwNwjZNeJyX4Z4UV.M2K5fEb4DYKb6HYbKuPEtgJD8AWGwEiLITm3abbQhZ0O4OFGoEw8hpDZKVGPfqbF2SzxFERxOLbeE0GnnFVH2Oj9tFhiw6g9K5ny8UfRvUMPOYJ25vTCvwwk.I2olhbuYmM5.Dsvwxc3zIeP1YGkOL2LZwLnw8AwZWpBWtBD7PUbqGtpB4tGwkLMCMEnC2btqyEggJL2FwgcNWtGr3zetL2qYEPh9c6FdBceTKGIho6ohzBlYpakjth0c0RKGCHcqHbNr6LHMhOmrtA43w9arXJqtujwT5lxLd8laBzCAseZ7XgFalh4b1S6GmLLgA1JtlKa.8VDKCT.zZ0nTDu5xTNkG3GQkGaHBHO9CqAeXHh0.v2OsayuAqodavICcJbYP8PLS.hn+S2Z49vKhXsbAVsaV9HoeV5FvIG0GmRcoi3WXOEBETnAVf7tXKP.oIknVEQfCCZuUjGB0nunQBqV1zYgQMd90LKYrff2igqGAwBPen6mi0CVFP8jIVzpw9APuzDU19r8UzfOxqVe70.G3wZ3rYwSnCw.qmm.h1lBgjFLOjyzFeTHLsCaV.CwKqlonkB5Mn9EH1WpSPYwE1FabxXZAuFfxHIs.FhLPPKlVFHDTel9In5J60GRbWrxWYGxLvyIQwCghf60Ex5chJ6pk37xyCaklmrjvZY0DJUj1F8NhDCEJJ8An2gEeWeI.8m+g6mymL6XdxwD6jefMY3o.g2JQ38VQ4jbOWj3Dar9Pu5djwYxVWSTHA3JCofLbXghS0iiueBwAeeB5UPLNtGlncM.N0Vd3eACiEEOHycHiSpBh6j6QF3.E817vpyCuOJ54nABzjYtTGoDYx0vUp4GGbZSBiCjZf1Nbq0aYYsHljkjqUbgH4fZ+TUzUgves4+uQPFHWEbchxDRPIvcLbke.vd7+PZGV6ttwVNarbCqkFZPXOUdfnZFr5jqy142FKXuPPF6w4MLsLx.nfRteOmwCfclkQZfR2b9d9vU5MkCTxnKZeEUj6.lAlS6meYdLA+.OvfXR8htH+FS8QQNq.nzGOP858tNmF0E+qXK0y1U83jNaBxFDv3snbDEFDhbZ+9VBExNcgXjd8sF4.FZCOcmd230Gg3GdMwQVOIpWqCVr.ZPivR+iWTp0+.1HYGxNI0ynuLZvTQMS5wRDGXCvW+DyDAjlPuPAmCkYbnwD2XRFNAxDKCFJQxuoKTmzQuYPx2OQJLm71HGYJjQ+aibsE7bs88e.ofXY0mHPJvr7c.3uIW8KEzdr53C6WL1GUPfRgdB0Gbx08IcO90psypa8SYLSduXKiMWsz2DuDxffdcdsjLPlgTMFgUgGU5mq+bNNgr8s3wgdNKQL1wHknqZv+3SE974GJ.tfJ92FNnWyVYODbghOFkU1mFu7a5vw11PJ21XvwgUv3653zlK40pRRHdB045TOdn+9Uxn6+MI5+O4f8dWCeWF7asVu03y4ZcTJjllS3KUiFdpCZ2syiiHBrHjvEsLlx2Vq+oTkFdJ2kUJxZWLkABUKo6W2y8f1UvsQJ1ZAtKILBK+v9MyYqt0FKO6gR.9vmyxuFFX1pDopfA.RF.WXWUDe17IhjR1k+OiRZruSXRq.ab5MlYa3h0.2lGrtfn7LxfjFtU8Ub74Jhqz8HHb401pRY.W9dbFoSMProXkt7kZP+vPL3qxoE9x9e4892q1O6XeYmt.fpxteSA6XqA92p0a9jsGjTPTuVjqL9wkfnFqpE2coM8LFhBiRrWz7zdtfMrtPQfsUKXAQj1.RmANoHA.XrfSPd1qzDNIvktFsTSBRtxVuiaGoXpPYPHK7u1XQKaRg38BAesnbtutS4bIw0tX.F.zSkQLFh9YlFwLx9F7xLeUJo6+T9JuA1HgmmOCpuC0vm2cZNRV4DToFOZWP6nj8.o0FRmbYIIXu799WqvHLCmpE232AO5+mZJk+68oxbC6q70aPoUU31Y2UXKpFXQjl8h.cbJLuQnCcg9CWmqThBZndLGhbTd+Ch8Bx9tbcZtBLsmAbOlKurZHvjPtjggky+nXrEP7p+FWGsiwrrWCH.yPMbk.O6RGQiapyREYvD+4u1V3.QW4DVJQSi+hFJHyxAlsIFhjZpcP9uH+7gaiRJ8LrefPKUCR+OoBX2sAEKv+5oViqdNwhL91kOtsM2XLPLJTvLAnAaMWPjjnQkI70F.0AqlhSL9VunEZfBoIfP0m7dwUOWhNeDjaEMCWHbF49cBmuQfa9skyKLjMYg0FPkEvX+5+OnceXv8gmFKHJ5+ePbi7oYh1r6MEwSgZn0sJcqFzJQ5aDhSVPpjYbGpKQ1Tc4sYQiM.BI57W2xYSGr6QLpL9ogT2lo+NC.CDWl+5GFfMMI3ARGOuefUKonQm67LJXtAwTlVSPfObR9QVQIrqjDpFM9Y7I1pKOFiO61w.4Lu33DZqDYLS4wkRxIUXb5.vbm9iWEeRSiTrYsk40BcXCQ4R50WJTwoP82Q4lkfPobHQM4FKwBGL2SBcp8g9bbMZDnZ16sUv8Yu7e8A";
	}
};
}

