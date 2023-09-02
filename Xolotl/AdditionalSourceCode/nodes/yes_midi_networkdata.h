namespace project
{

struct yes_midi_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "yes_midi";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "315.nT6K8CFOAzXB.XgD6TBDMaS.TQH2cksu4okiQQYh1uRD+ykOu8vj0....4z793fbRM8Cw..L.7B.M7nuifUT8rEaw1.z+fNJYe4s8QOF2CpIVIAg3.kjV3tH2TDTc0NfdISdzKgDxY1UBLYIcZo3DjgUKY73DK2EmpifU.POaezG0TTbrJxeNVClkreNd9fX1BzqYxPUR3DCGvTd6Qqwf3nwZK1df9diDe44nr5el8DKYn+FBqB8c5n2DUOkryjYSjJVJR4jn5OG+8jcXW7ojmVhP3CKC1psKaU72vAjFI.owbrT3wZv6IGDQPmrgVBlvYI1SKmsVA5DZ.BTBDAlDugJQFr4raJB.gSbZpuiYFH091PC43VLP4CVqPE.AXgEPWJDGhKhtMzpN6GY.rXm.WNOSR.HxVeB14MC";
	}
};
}

