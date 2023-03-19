namespace project
{

struct files_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "files";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "420.nT6K8CVQBTMC.X1kLcB3xha.H4QCZll1bjOT7SvQBecv09mH.7caXuKMfPHFGiIvutLJoLfO..D.DAfq0XEEcnqmv2hQXUMylJK9SqFCzp90WwtZKpE0fuSF8KTINxpVN3qAK68Td926AU5OWGr.qFAEQVcS78L8Jd4bvQBUhAFZ0O9EjBnUk9yg4cWcdXWU6YGwG+gw4u.vF4wDznm0OrMJPk.rxnOcNcro77ZpzFGY0KWJarLHTXfe8Y1X0bj0OJ1fVjzGtJLeVosnIliZLyqBsp9oy3cd8EPWFU14cwNWB40jTcwhEJLj.jPv5L9CiSWYwhFYfAH7B6keEnpJguaZ4P3eY2cREJSjpPQBkJNL4PSRCQMVgU83apz2MaKXBlnzlLgEHyB5c7viXl+aAePq0l3Al3.fjl8Db.RpFnBHfYDMlaCDG.JIFpP3AF7FbW0I6sF7fdFvIjwpSXI.b0pU4qxvElQoCX49ESC8ZVPKElzUqRN2Ase94DssGzxzlL2Liy2oLuWhiGXJ5qgFN.DzeLebmaVwJNiEipCN2IWjjEcO";
	}
};
}

