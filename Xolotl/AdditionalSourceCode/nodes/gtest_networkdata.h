namespace project
{

struct gtest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "gtest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "367.nT6K8CFjBzxB.X2z9PBDKc9COR5xicqs0WzlHfdDWbPOC5CLj91F...EMMw5wOCnLEvL.LC.0.fmPLjNm4TEAamyu6UsEnImmoBAeeESIgls06hpYKpE0bOOBaM4G6eytPyoJHzrC7846KQBpsbUTMi8kS44VYKnZl7ySf5KOXuIHznFlv2yWYNFtYI3.2xwVFYDg1X7krs.noUGibfTSBRDINjzR.RTaMPyOcGLNdrY5d96wG0NPKpAH1R1hZ6pYmcwZbtkDZp.1eiwPlJyFHrIzjw1k88jE2POX1.B8dz0Sq.oT1XdlUArcv8l7x7f5LY+fiw4LrgkQqIsKbrJZvo5cpHRhnviq.BXFQjw7.0gGrXERrV7SvFgu7Pw0xfxZeWAxsfs59nYYWqPMgZOGWSfgQF33fsTXP78oyWlbGlnzTcSofwwG3visreqvaCRa9QWCihAR7AiEXii0Iz3o5C.tW7DXw9aAiDrNxJjG.";
	}
};
}

