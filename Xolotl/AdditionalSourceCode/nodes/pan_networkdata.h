namespace project
{

struct pan_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "380.nT6K8CF2AT4B.XE0.QBDMiN8B226F4qlIrTZVDBImWcLDzSyF8fhd...RIUn6eILRxfM.XC.2.Pk2tFk2fk2uKLpDx03KWLCIzCzCz5PS+aWvFSFsKzrp4+lWl6mh3cNIoyuc0jhzpIDvOhXaI.169IOZ7VD6g6.Y6xvUO33LuSy9fgl4kB0put3WlBo23MUOv1abz+pU.M2D4oL3Gq3ErdKp1g67iyBflVRwVCjuvNLquRlQN+1FZ1XNFS5eKV0t+SnHoPyLsEg86gSKzDRTAQLHAHH.IxFflv.oCygswDMpWGoNXyLJxc9HljHB1FJzm2kEm8AEobc.8DIAWIgdf10aUXnY57ztvN1cXHOkvNKf.CPfwoT6zBNfaKh9eXG39Bioz3x7X81gPFplP4vDGbhgrOlY5DI..iHhxk4NV6CFocGiky84Jt.hufaaolsKlAHw.C3Jni8dZq37NNs+7JnoNvQNjOc0lEbrrMv1xbD2O27s84twFDBVQA";
	}
};
}

