#pragma once
#include "formula.h"
class BooleanExpression
{
public:
	Formula* F;
	int max;//количество переменных
	int count;//количество формул

	friend BooleanExpression begin(std::ifstream& in);
	BooleanExpression(int& counter, char** (&x), int(&countX));
	BooleanExpression(const BooleanExpression& x);

	bool _calc(const int &i);
	void truthTabel();
	void cnf(std::ofstream &out);
	void dnf(std::ofstream &out);
	void zheg(std::ofstream& out);


	bool isFull(std::ofstream& out);

	bool isSavingZero();
	bool isSavingOne();
	bool isSelfSecond();
	bool isMonotonous();
	bool isLinear();
};