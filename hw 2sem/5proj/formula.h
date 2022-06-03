#pragma once
#include <string>
#include <stack>
#include "formulaNode.h"
#include<cstring>
//#include "errors.h"
//size_t strlen(const char* x)
//{
//	size_t res = 0;
//	const char* i = x;
//	while (*i != '\0') ++res;
//	return res;
//}
class Formula {
	FormulaNode* root;
	
	//FormulaNode* _Postfix2Tree_(const char*);
	FormulaNode* Postfix2Tree_(const char*);
	void Infix2Postfix_(const char*, char*);
	void InfixFilter_(const char*, char*);

	static const unsigned char ActionsTable[][11];
	static int ActionsRowNumber(char ch);
	static int ActionsColNumber(char ch);
public:
	int countX = 0;

	Formula()
	{
		root = nullptr;
		size_t Len = 0;
		countX = 0;
	}
	Formula(const char* str) {
		size_t Len = strlen(str);
		Len = (Len < 10) ? 20 : 2 * Len;
		char* str_infix = new char[Len];
		char* str_postfix = new char[Len];

		
		InfixFilter_(str, str_infix);
			Infix2Postfix_(str_infix, str_postfix);
			root = Postfix2Tree_(str_postfix);
			calc();
		delete[] str_infix;
		delete[] str_postfix;
	}
	/*Formula(const char* str, const int flag) {
		size_t Len = strlen(str);
		Len = (Len < 10) ? 20 : 2 * Len;
		char* str_infix = new char[Len];
		char* str_postfix = new char[Len];

		try {
			InfixFilter_(str, str_infix);
			Infix2Postfix_(str_infix, str_postfix);
			root = _Postfix2Tree_(str_postfix);
		}
		catch (...) {
			delete[] str_postfix;
			delete[] str_infix;
			root = nullptr;
			throw;
		}
		delete[] str_infix;
		delete[] str_postfix;
	}*/
	bool calc()const {
		if (root) return root->calc();
		return 0;
	}
	bool _calc()const
	{
		if (root) return root->_calc();
		return 0;
	}
	bool calcNF() const
	{
		if (root) return root->calcNF();
		return 0;
	}
	std::string str()const {
		if (root) return root->str();
		return std::string("");
	}
};
