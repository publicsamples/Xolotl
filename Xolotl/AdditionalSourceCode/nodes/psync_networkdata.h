namespace project
{

struct psync_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "psync";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "428.nT6K8ClUCTQC.Xij7XB7NiC.HvLK4JB.oB6iFyduTgfjFnLfrDIKBXhrIRI1ZfBG9AY78EC.v.PL.7rxT3elhnsL9px4DSv9O02lL5rN8v.sugSM69nlbFunsmOIytr3G6YHCi8RPmUTaMA+nqdz2lS6JsoPf8vLSsTNWXqcDzWG4LVeTXvoTD0jJ4goUUW4HP6+Ei8MFZOruthy0tLwIo0ZNFfCaJHdxFXH+zNRYEqTXRbDJt+NtKhbr5JGKN1gEOoyqLJw6a7Fi54Ieip3.b0W0rhkPiEBeL+OQSwbvkDCANkXGYazZR2.Yv+jKVPnxDWknJbAcUrCrkNvC3nDIAZHIMfhQDAfvp0..I.HLFR7YhyHIlvAfvF.9VA9hdDfNXG3rV0PEkAS3QF3i8tHR7iQfrhUPejKXdgV65ATKDJxJ9hcgbzXbdeQ1NzAQlzSsA25u4VbVXF.3ww1Rof6i9pJr65scVRRFTqHqUP66bmFLAL3.krqfBzClLIfMbbbvBDCQhcdZMZ.IQP7lBpYHhkVglk6ZA97Eze+zNGRrhrDwy40U.zcvNJXtG.";
	}
};
}

