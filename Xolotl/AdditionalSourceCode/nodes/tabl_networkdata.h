namespace project
{

struct tabl_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "tabl";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "202.nT6K8CFS.TfA.HuRi.BPqsM.WMI0nPo5gS3J2bbidArf0Gum9bLbBbh6Iwtk98TAcHnQSbzAkI9kAltnsRb.ua6sg5TEuYUMDH9GBH9qstzrLGMXCNL1Mv6D1TFveqhYPvixD7p88TGOJ3skxHcbaaociSo.3YzphGNtS5AI3WEyf3QGzAkJ3a7541Emof1I.3WPffeAG2PuLMAHPIpXV8vkNvjAXzf0p6v7RGJPwKJhA2KFzA.VSqYQBg6CGKJvEbmBVMramCilY.";
	}
};
}

