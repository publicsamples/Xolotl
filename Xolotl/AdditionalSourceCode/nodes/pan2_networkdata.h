namespace project
{

struct pan2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "388.nT6K8ClMBT8B.X0z9PBDMiN8B226F4qlIrTZVDBImWsNLtIPOeWQO...ojJz8uTjRo.M.PC.1..k2fk2uKLpLx03KWLCYDTDTz1PS+aWvFSJsJzrp4+lWl6mh3ctH4CmeKCMmPY0DB3GQrsDQrGtCztLb0CNNy6zrNV7rMxqG0put3WlBo23MUPv1abz+pU.M2D4oL3Gq3ErdKp1Ud6ZA73r.noEkXqAxWXGl0WIaLGiI8uEqZ2eISn7nYVKB62CmTnIDoBfXPBOP3AjM.MgXu6k.owaA3vbXYLQi50QpC1LkhbmOhEQhfkwiB8tr3rNRII3JYDTztdqxBMSmm1E1wtCC4oD1tyAz.BPf.vTqc.TGZECfaDh9eX.beiwTZbYZrd6PHCqIqbX3AmnP1uYlNRB.PDTbZGqSXY.oIC.f6b4betBJf.Wv0Vpz1E6.jafguROVCCRsdOTQYvCa7mAfl5.m3Pp.QA6DictXYUDz.QW1PCKlnEq4f+Oyb2AsamfPHnGE.";
	}
};
}

