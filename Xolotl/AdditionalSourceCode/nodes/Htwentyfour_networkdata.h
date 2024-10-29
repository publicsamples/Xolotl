namespace project
{

struct Htwentyfour_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "Htwentyfour";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "140.nT6K8CRscP..xiPGb.0ha.hEIQgHqlTrk0MTG6FIX.WQUULGykoioev+cr15Sx4x+c.P8IUtJgfmQctD5c3MV1rRXswxtsqDA7Mct73sWYh.3UlUAwqRTIpj.7sk4XkwKjPvuXssA54rKQqiigyO1FutoQshz.7HVff2AuQspDv..7EBvJJRPczKDE.";
	}
};
}

