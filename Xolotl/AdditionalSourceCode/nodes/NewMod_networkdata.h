namespace project
{

struct NewMod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "NewMod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "127.nT6K8Cxk0N..hhzFZ.2RUzXKMZ1oARQrKiKizvLqzwTUQOS4k1zO+G1abanst9ObarBP9zwjusPnlrX3OmdvP89bZ7wryf7GQcszbjoHL42Fqx7ITBkNAx+XGr2Emvwjm4d7QxBBuTXDjBuwJTV0QP9CIL4YzrRbUE..kdGgn.";
	}
};
}

