#pragma once
#include <string>
#include <iostream>
#include<fstream>
#include <cmath>
//#include "errors.h"
#include"avltree.h"

class FormulaNode {
public:
	virtual bool calc() const = 0;
	virtual bool _calc() const = 0;
	virtual bool calcNF() const = 0;
	virtual std::string str() const = 0;
	//virtual bool calc(bool)
	virtual ~FormulaNode() {}
};
//------------------------------------------------------
class NumNode : public FormulaNode {
	bool num;
public:
	NumNode(bool x) : num(x) { }
	bool calc() const { return num; }
	bool _calc() const { return num; }
	bool calcNF() const { return num; }
	std::string str() const {
				if (num < 0)
					return std::string("(") + std::to_string(num) + std::string(")");
		return std::to_string(num);
	}
};
//------------------------------------------------------
class BinNode : public FormulaNode {
protected:
	FormulaNode* left, * right;
public:
	BinNode(FormulaNode* L, FormulaNode* R) : left(L), right(R) {}
	~BinNode() {
		delete left;
		delete right;
		left = right = nullptr;
	}
};
//------------------------------------------------------
class CnNode : public BinNode {
public:
	CnNode(FormulaNode* L, FormulaNode* R) : BinNode(L, R) {}
	bool calc()const { return left->calc() & right->calc(); }
	bool _calc()const { return left->_calc() && right->_calc(); }
	bool calcNF()const { return left->calcNF() && right->calcNF(); }
	std::string str() const {
		return left->str() + " & " + right->str();
	}
};
//------------------------------------------------------
class DzNode : public BinNode {
public:
	DzNode(FormulaNode* L, FormulaNode* R) : BinNode(L, R) {}
	bool calc()const { return left->calc() | right->calc(); }
	bool _calc()const { return left->_calc() || right->_calc(); }
	bool calcNF()const { return left->calcNF() || right->calcNF(); }
	std::string str() const {
		return left->str() + " v " + right->str();
	}
};
//------------------------------------------------------
class ImplicNode : public BinNode {
public:
	ImplicNode(FormulaNode* L, FormulaNode* R) : BinNode(L, R) {}
	bool calc()const { return left->calc() <= right->calc(); }
	bool _calc()const { return left->_calc() <= right->_calc(); }
	bool calcNF()const { return left->calcNF() <= right->calcNF(); }
	std::string str() const {
		return left->str() + " > " + right->str();
	}
};
//------------------------------------------------------
class ReverseImplicNode : public BinNode {
public:
	ReverseImplicNode(FormulaNode* L, FormulaNode* R) : BinNode(L, R) {}
	bool calc()const { return left->calc() >= right->calc(); }
	bool _calc()const { return left->_calc() >= right->_calc(); }
	bool calcNF()const { return left->calcNF() >= right->calcNF(); }
	std::string str() const {
		return  left->str() + " < " + right->str();
	}
};
//------------------------------------------------------
class XORNode : public BinNode {
public:
	XORNode(FormulaNode* L, FormulaNode* R) : BinNode(L, R) {}
	bool calc()const { return left->calc() != right->calc(); }
	bool _calc()const { return left->_calc() != right->_calc(); }
	bool calcNF()const { return left->calcNF() != right->calcNF(); }
	std::string str() const {
		return left->str() + " + " + right->str();
	}
};
//------------------------------------------------------
class EqNode : public BinNode {
public:
	EqNode(FormulaNode* L, FormulaNode* R) : BinNode(L, R) {}
	bool calc()const { return left->calc() == right->calc(); }
	bool _calc()const { return left->_calc() == right->_calc(); }
	bool calcNF()const { return left->calcNF() == right->calcNF(); }
	std::string str() const {
		return left->str() + " = " + right->str();
	}
};
//------------------------------------------------------
class ShefferNode : public BinNode {
public:
	ShefferNode(FormulaNode* L, FormulaNode* R) : BinNode(L, R) {}
	bool calc()const { return !(left->calc() & right->calc()); }
	bool _calc()const { return !(left->_calc() && right->_calc());}
	bool calcNF()const { return !(left->calcNF() && right->calcNF()); }
	std::string str() const {
		return left->str() + " | " + right->str();
	}
};
//------------------------------------------------------
class PearsNode : public BinNode {
public:
	PearsNode(FormulaNode* L, FormulaNode* R) : BinNode(L, R) {}
	bool calc()const { return !(left->calc() | right->calc()); }
	bool _calc()const { return !(left->_calc() || right->_calc()); }
	bool calcNF()const { return !(left->calcNF() || right->calcNF()); }
	std::string str() const {
		return left->str() + " ^ " + right->str();
	}
};
//------------------------------------------------------
//------------------------------------------------------
class InversionNode : public BinNode {
public:
	InversionNode(FormulaNode* L, FormulaNode* R) : BinNode(L, R) {}
	bool calc()const { return !(right->calc()); }
	bool _calc()const { return !(right->_calc()); }
	bool calcNF()const { return !(right->calcNF()); }
	std::string str() const {
		return " ~(" + right->str() + ")";
	}
};
class ParametrValue {
	std::string ch;
	bool val=0;
public:
	ParametrValue(std::string c, double value) : ch(c), val(value) {}
	bool getValue() const { return val; }
	std::string getStr() const { return ch; }
	bool makeTrue() { val = 1; return val; }
	bool makeFalse() { val = 0; return val;}
	bool operator<(const ParametrValue& X)const { return ch < X.ch; }
	bool operator==(const ParametrValue& X) const { return ch == X.ch; }
};
//------------------------------------------------------
namespace global {
	extern AVLTree<ParametrValue> Workspace;
}
//------------------------------------------------------
class ParamNode : public FormulaNode {
	std::string x;	
public:
	ParamNode(std::string s) : x(s) { }
	bool calc() const {
		auto pos = global::Workspace.find(ParametrValue(x, 0));
		if (pos != global::Workspace.end()) {
			return (*pos).getValue();
		}
		else {
			bool tmp;
			//std::cout << x << " = ";
			//std::cin >> tmp;
			//std::cin.ignore();
			global::Workspace.insert(ParametrValue(x, 0));
			return 0;
		}
	}
	bool _calc() const 
	{

		auto pos = global::Workspace.find(ParametrValue(x, 0));
		if (pos != global::Workspace.end()) {
			return (*pos).getValue();
		}
		else {
			bool tmp;
			//std::cout << x << " = ";
			//std::cin >> tmp;
			//std::cin.ignore();
			global::Workspace.insert(ParametrValue(x, 0));
			return 0;
		}
	}
	bool calcNF()const
	{
		auto pos = global::Workspace.find(ParametrValue(x, 0));
		if (pos != global::Workspace.end()) {
			return (*pos).getValue();
		}
		else {
			bool tmp;
			//std::cout << x << " = ";
			//std::cin >> tmp;
			//std::cin.ignore();
			global::Workspace.insert(ParametrValue(x, 0));
			return 0;
		}
	}
	bool change(const bool& a)
	{
		auto pos = global::Workspace.find(ParametrValue(x, a));
		if (pos != global::Workspace.end()) {
			return (*pos).getValue();
		}
		else
		{
			global::Workspace.insert(ParametrValue(x, a));
			return a;
		}
	}
	std::string str() const {
		return x;
	}
};
//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------
//#include "functions.h"
//class FuncNode : public UnarNode {
//	int funcNumber;
//public:
//	FuncNode(char s, FormulaNode* node) : UnarNode(node) {
//		funcNumber = FunctionsTable::FunNumberByShortName(s);
//	}
//	FuncNode(const char* s, FormulaNode* node) : UnarNode(node) {
//		funcNumber = FunctionsTable::FunNumberByName(s);
//	}
//	bool calc() const {
//		//return (FTable[funcNumber].fun) (next->calc());
//		return (FunctionsTable::get(funcNumber).fun) (next->calc());
//	}
//
//	std::string str()const {
//		/*		return std::string(FTable[funcNumber].Name)
//					+ "(" + next->str() + ")";
//		*/
//		return std::string(FunctionsTable::get(funcNumber).Name)
//			+ "(" + next->str() + ")";
//	}
//};

class UnarNode : public FormulaNode {
protected:
	FormulaNode* next;
public:
	UnarNode(FormulaNode* node) : next(node) {}
	~UnarNode() { if (next) delete next; next = nullptr; }
};
class InvNode : public UnarNode {
public:
	InvNode(FormulaNode* node) : UnarNode(node) {}
	bool calc()const { return !next->calc(); }
	bool _calc() const { return !next->_calc(); }
	bool calcNF() const { return !next->calcNF(); }
	std::string str() const {
		return " - (" + next->str() + ")";
	}
};

//------------------------------------------------------
class AssignmentNode : public FormulaNode {
	ParamNode* left;
	FormulaNode* right;
public:
	AssignmentNode(FormulaNode* L, FormulaNode* R)
		: right(R), left(nullptr) {
		left = dynamic_cast<ParamNode*>(L);
		/*if (left == nullptr)
			throw ErrorRValue();*/
	}
	std::string str() const {
		return left->str() + " := " + right->str();
	}

	bool calc() const {
		double result = right->calc();
		std::string paramName = left->str();
		auto pos = global::Workspace.find(ParametrValue(paramName, 0));
		if (pos != global::Workspace.end()) {
			global::Workspace.erase(pos);
		}
		global::Workspace.insert(ParametrValue(paramName, result));
		return result;
	}

	~AssignmentNode() {
		delete right;
		delete left;
		right = left = nullptr;
	}
};
//------------------------------------------------------
//------------------------------------------------------






