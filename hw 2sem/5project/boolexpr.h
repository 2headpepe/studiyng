#pragma once
#include "formula.h"
class BooleanExpression
{
public:
	Formula* F;
	int max;
	int count;
	BooleanExpression(int &counter, char** (&x),int (&countX))
	{
		max = countX;
		count = counter;
		F = new Formula[counter];
		for (int i = 0; i < count; ++i)
		{
			F[i] = Formula(x[i]);
		}
	}
	bool _calc(const int &i);
	void truthTabel();
	void cnf();
	void dnf();
	void zheg();


	bool isFull();

	bool isSavingZero();
	bool isSavingOne();
	bool isSelfSecond();
	bool isMonotonous();
	bool isLinear();
};