namespace project
{

struct PitchMod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "PitchMod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "461.nT6K8ClGDzgC.X+z.QBLmia.y116PqPqYfhrV4chPdDf3.+IX+Yb9gBxubK3Mdn0lRgM.PC.0.fi0QxZUEM+3yqQYUK.uVU+RmorV4DTf22Isv7FsnOvaT9nyGy5jSVU02kFAuTp7vKBS4l5aIvEV275pT8wnbBWeMSufn7UcXFDG8y0IuL.5GHgZ5DPP7tzGdaz4W+Ke5W1Hsn1EMDutmRC0rH8gVBOJruR4n0F33Sayw2Ty61TzE3ky6hUXdoyOSlLIcbHF8QwqNENOD6RNY2OC5X5Cq2ta0jpAnkd.owngiVhGN5pQrNWjtezT7Mf7PhQqAilTq0jjhj5A5.wdUX1TivPAHmyehfxY.U+RFfSfFZLBUvPHLoAjffA.I..l4ra..2TvzfaYzt9vGNadlxJ6jx7mLHLJPmbjUiKFqXJzBcXCCBLiwvwlNcb9Ls1F0n7h5lQ2uEKvbfHil.7wsSvgHTP+zdPILVmWAXIUhYaB19N3ZOd1ua725lTgNcZGJs3hkdtSMQCUAx6NjPmknAbPffqfD3mR2qrhxLLzB24iqPvWN8FHu0pTQ50lMR67oUZG.NkoJ9EamIFxVJA9bZkbyJKhtemGn5.9UA";
	}
};
}

