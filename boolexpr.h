#pragma once
#include "formula.h"
class BooleanExpression
{
public:
	Formula* F;
	int max = 0;
	BooleanExpression(int &count, char** (&x),const int (&countX))
	{
		max = countX;
		F = new Formula[count];
		for (int i = 0; i < count; ++i)
		{
			F[i] = Formula(x[i]);
		}
	}
	bool _calc();
	void truthTabel();
};