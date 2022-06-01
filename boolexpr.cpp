#include"boolexpr.h"
void BooleanExpression::truthTabel()
{
	std::string str = "00";
	int i = 0;
	auto iter = global::Workspace.begin();
	while (iter != global::Workspace.end())
	{
		iter.now->data.makeTrue();
	}
	//iter.makeTrue();
}

bool BooleanExpression::_calc()
{
	
	return 0;
}