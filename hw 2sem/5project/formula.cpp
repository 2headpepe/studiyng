#include "formula.h"
//-----------------------------------------------------
FormulaNode* Formula::Postfix2Tree_(const char* str) {
	int index = 0; // Íîìåð ýëåìåíòà âî âõîäíîé ñòðîêå
	std::stack<FormulaNode*> S;
	char ch;
	FormulaNode* result, * left, * right;
	try {
		while ((ch = str[index]) != '\0') {
			left = right = nullptr;
			switch (ch) {
			case '&':
				if (S.empty()) throw 1; right = S.top(); S.pop();
				if (S.empty()) throw 1; left = S.top(); S.pop();
				result = new CnNode(left, right);
				break;
			case 'v':
				if (S.empty()) throw 1; right = S.top(); S.pop();
				if (S.empty()) throw 1; left = S.top(); S.pop();
				result = new DzNode(left, right);
				break;
			case '>':
				if (S.empty()) throw 1; right = S.top(); S.pop();
				if (S.empty()) throw 1; left = S.top(); S.pop();
				result = new ImplicNode(left, right);
				break;
			case '~':
				if (S.empty()) throw 1; right = S.top(); S.pop();
				if (S.empty()) throw 1; left = S.top(); S.pop();
				result = new InversionNode(left, right);
				break;
			case '<':
				if (S.empty()) throw 1; right = S.top(); S.pop();
				if (S.empty()) throw 1; left = S.top(); S.pop();
				result = new ReverseImplicNode(left, right);
				break;
			case '+':
				if (S.empty()) throw 1; right = S.top(); S.pop();
				if (S.empty()) throw 1; left = S.top(); S.pop();
				result = new XORNode(left, right);
				break;
			case '=':
				if (S.empty()) throw 1; right = S.top(); S.pop();
				if (S.empty()) throw 1; left = S.top(); S.pop();
				result = new EqNode(left, right);
				break;
			case '^':
				if (S.empty()) throw 1; right = S.top(); S.pop();
				if (S.empty()) throw 1; left = S.top(); S.pop();
				result = new PearsNode(left, right);
				break;
			case '|':
				if (S.empty()) throw 1; right = S.top(); S.pop();
				if (S.empty()) throw 1; left = S.top(); S.pop();
				result = new ShefferNode(left, right);
				break;

			default:

				if (ch == 'x')
				{
					std::string res = "x";
					while ((str[++index] >= '0') && (str[index] <= '9'))  res += str[index];
					--index;
					result = new ParamNode(res);
				}
				else if (ch == '0')
					result = new NumNode(0);
				else if(ch <= '1')
					result = new NumNode(1);
					

			}
			S.push(result);
			++index;
		}
		if (S.size() > 1) {
			left = right = nullptr;
			throw 2;
		}
		result = S.top();
		return result;
	}
	catch (int E) {
		if (left) delete left;
		if (right) delete right;
		while (!S.empty()) {
			left = S.top();
			S.pop();
			delete left;
		}
		//throw ErrorPostfix(str, index);
	}
}

//-----------------------------------------------------
const unsigned char Formula::ActionsTable[10][11] = {
	//\0 v ~ & > < + | ^ = P
	 { 7,2,2,2,2,2,2,2,2,2,1},// \0
	 { 3,3,2,2,3,3,3,3,3,3,1},// v
	 { 3,3,3,3,3,3,3,3,3,3,1},// ~
	 { 3,3,2,3,3,3,3,3,3,3,1},// &
	 { 3,2,2,2,3,3,2,2,2,3,1},// >
	 { 3,2,2,2,3,3,2,2,2,3,1},// <
	 { 3,3,2,2,3,3,3,3,3,3,1},// +
	 { 3,3,2,2,3,3,3,3,3,3,1},// |
	 { 3,3,2,2,3,3,3,3,3,3,1},// ^
	 { 3,2,2,2,3,3,2,2,2,3,1} // =
};
//-----------------------------------------------------
int Formula::ActionsRowNumber(char ch) {
	switch (ch) {
	case 0: return 0;
	case 'v':return 1;
	case '~':return 2;
	case '&':return 3;
	case '>':return 4;
	case '<':return 5;
	case '+':return 6;
	case '|':return 7;
	case '^':return 8;
	case '=': return 9;
	}
	throw 11;
}
//-----------------------------------------------------
int Formula::ActionsColNumber(char ch) {
	switch (ch) {
	case 0: return 0;
	case 'v':return 1;
	case '~':return 2;
	case '&':return 3;
	case '>':return 4;
	case '<':return 5;
	case '+':return 6;
	case '|':return 7;
	case '^':return 8;
	case '=': return 9;
	}
	if (ch == 'x') return 10;
	if (ch >= '0' && ch <= '9') return 10;
	throw 11;
}
//-----------------------------------------------------
void Formula::Infix2Postfix_(const char* in, char* out) {
	int i = 0, j = 0; // i - èíäåêñ âî âõîäíîé ñòðîêå, j - â âûõîäíîé
	int row, col;
	char prev;
	unsigned char action;
	std::stack<char> S;
	do {
		col = ActionsColNumber(in[i]);
		row = S.empty() ? 0 : ActionsRowNumber(S.top());
		action = ActionsTable[row][col];
		switch (action) {
		case 1: out[j] = in[i]; ++j; ++i; break;
		case 2: S.push(in[i]); ++i; break;
		case 3: out[j] = S.top(); ++j; S.pop(); break;
		//case 5: throw ErrorBracketsClose(instr, i); break;
		//case 6: throw ErrorBracketsOpen(instr, i); break;
		case 7: out[j] = '\0'; break;
		//case 8: throw ErrorFunctionBrackets(instr, i); break;
		//case 9: throw ErrorRValue(); break;
		}
	} while (action != 7);

}

void Formula::InfixFilter_(const char* in, char* out) {
	int i = 0, j = 0; 
	char ch, prev = 0;
	char buf[256]; int bufLen = 0;
	while ((ch = in[i++]) != 0) {
		if ((ch == ' ') || (ch == '\t'))
		{
			bufLen = 0;
			buf[0] = '\0';
			continue;
		}

		if (ch =='x') 
		{
			buf[bufLen++] = ch;
		}
		else if (bufLen >= 1)//(x1 * x2)->0~(x1*x2)->0x1x2*~
		{
			if((ch>='0')&&(ch<='9'))
				buf[bufLen++] = ch;
		}
		else if (!(bufLen) && (ch != 'x'))
		{
			if ((ch == '~') && ((prev == 0 ) || ((prev == '(') && (bufLen == 0))))
				out[j++] = '0';
		}
		else {
			
			if (bufLen > 1)
			{ 
				buf[bufLen] = '\0';
				//outstr[j++] = FTable[FunNumberByName(buf)].ShortName;
				//outstr[j++] = FunctionsTable::get(FunctionsTable::FunNumberByName(buf)).ShortName;

				bufLen = 0;
			}
			
		}
		out[j++] = ch;
		prev = ch;
	}
	//if (bufLen > 1) throw InfixError("Function without arguments");
	//if (bufLen > 0) out[j++] = buf[0];
	out[j] = '\0';
}

//-----------------------------------------------------------