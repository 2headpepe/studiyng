#include "TuringMachine.h"

std::string TuringMachine::calc(std::string &init, int maxsteps)
{
	std::string strTmp = strToNormal(init, maxLen);

	int step = 0, ruleNum = 0, i = maxLen / 2 - init.length() / 2;
	char* condTmp = rules[0].cond;

	while ((step < maxsteps) && (condTmp != endCond))
	{

		if (rules[ruleNum].in != strTmp[i])
		{
			++ruleNum;//проверка подходит ли это правило
		}
		
		strTmp[i] = rules[ruleNum].out;
		condTmp = rules[ruleNum].newCond;
		if (condTmp == endCond) break;
		switch (rules[ruleNum].dir)
		{
		case 'R': ++i; break;
		case 'L': --i; break;
			// 'N' -> 0 changes
		}
		ruleNum += rules[ruleNum].shift; // действуем в соответствии с правилом


		++step;
		//std::cout << strTmp<<std::endl;
		if ((ruleNum >= countRules)||(ruleNum < 0))
		{
			std::cout << "out of rules(my bad)";
			return strTmp;
		}
		if ((i >= maxLen)||(i<0))
		{
			std::cout << "out of str";
			return strTmp;
		}
	}
	return strTmp;
}
bool charEQ(char* x,char* y)
{
	bool flag=0;
	char(*first) = x;
	char(*second) = y;
	while (*x != '\0')
	{
		if (*x != *y)
		{
			flag = 1;
			break;
		}
		++x;
		++y;
	}
	if (*y != '\0') return 0;
	return !flag;
}
void shifting(rule* (&rls), const int(&count))
{
	bool flag=0;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if (charEQ(rls[i].newCond, rls[j].cond))
			{
				rls[i].shift = j - i;
				break;
			}


		}
	}
}
char* endingCond(rule* (&rules), const int& len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if (charEQ(rules[i].newCond,rules[j].cond)) break;
			if (j == len - 1) return rules[i].newCond;
		}
	}
	std::cout << "oops... there is not final cond";
	return rules[0].newCond;
}

std::string strToNormal(const std::string(&str), const int len)
{
	std::string newStr = "";
	newStr.append(len, '0');
	for (int i = len / 2 - str.length() / 2; i < len / 2 + str.length() / 2; ++i)
	{
		newStr[i] = str[i - len / 2 + str.length() / 2];
	}
	return newStr;
}


TuringMachine TuringMachine::begining(std::ifstream(&prog), std::ifstream(&input), std::ofstream(&out))
{
	char c;
	int countRule = 1;
	while ((c = prog.get()) != EOF)
	{
		if (c == '\n') ++countRule;
	}
	rule* rls = new rule[countRule];
	prog.clear();
	prog.seekg(0);

	int i = 0, j = 0, iterTmp = 0;
	int condition = 0;
	int lenCond = 0;
	countRules = countRule;
	rules = new rule[countRule];
	maxLen = 0;
	std::vector<char> x;
	while ((c = prog.get()) != EOF)
	{
			if ((c != 'q') && (j == 0))//q
			{
				out << "ERROR";
				break;
			}
			if ((j++) == 0) c = prog.get();//skip q
			if (j == 1)//cond
			{
				while (c != ' ')
				{
					x.push_back(c);
					c = prog.get();
				}
				rules[i].cond = new char[x.size()+1]{ 0 };
				for (int k = 0; k < x.size(); ++k)
				{
					rules[i].cond[k] = x[k];
				}
				rules[i].cond[x.size()] = '\0';
				x.clear();
				++j;
			}
			if (((c = prog.get()) != '\n') && (j == 2))//in
			{
				rules[i].in = c;
				++j;
			}
			else out << "ERROR";
			if (j == 3)//skip ->
			{
				for (int k = 0; k < 4; ++k)
				{
					if ((c = prog.get()) != '\n')
						x.push_back(c);
					else out << "ERROR";
				}
				std::vector<char> tmpVec = { ' ','-','>',' ' };
				if (tmpVec != x) out << "ERROR";
				else
				{
					if ((c = prog.get()) != 'q') out << "ERROR";
				}
				x.clear();
				++j;
			}
			if (j == 4)//newCond
			{
				while ((c = prog.get()) != ' ')
				{
					x.push_back(c);
				}
				rules[i].newCond = new char[x.size()+1];
				for (int k = 0; k < x.size(); ++k)
				{
					rules[i].newCond[k] = x[k];
				}
				rules[i].newCond[x.size()] = '\0';
				x.clear();
				++j;
			}
			if (j == 5)
			{
				c = prog.get();
				rules[i].out = c;
				++j;
			}
			if (j == 6)
			{
				c = prog.get();
				c = prog.get();
				if ((c != 'L') && (c != 'R') && (c != 'N')) out << "ERROR";
				else rules[i].dir = c;
			}
			c = prog.get();
			++i;
			j = 0;
		
	}
	int tick = 0;
	std::string init;
	while ((c = input.get()) != ' ')
	{
		maxLen *= 10;
		maxLen += c - 48;
	}
	while ((c = input.get()) != ' ')
	{
		tick *= 10;
		tick += c - 48;
	}
	while ((c = input.get()) != EOF)
	{
		init += c;
	}
	shifting(rules, countRules);
	endCond = endingCond(rules, countRules);
	std::string res = calc(init, tick);
	int start = 0, end = 0;
	for (int i = 0; i < res.length(); ++i)
	{
		if ((res[i] == '1') && (start == 0))
		{
			start = i;
			end = i;
		}
		else if (res[i] == '1')
		{
			end = i;
		}
	}
	for (int i = start; i <= end; ++i) out << res[i];
	prog.close();
	input.close();
	out.close();
	return *this;
}



int main(int argc, char* argv[])
{
    /*if (argc < 4)
    {
        std::cout << "no needed arguments";
        return -1;
    }*/

	std::ifstream prog;
	prog.open("prog.txt");
	if (!prog.is_open())
	{
		std::cout << "did not opened program";
		return -2;
	}
		
	std::ifstream in;
	in.open("in.txt");
	if (!in.is_open())
	{
		std::cout << "did not opened input information";
		return -3;
	}

	std::ofstream out;
	out.open("out.txt");
	if (!out.is_open())
	{
		std::cout << "did not opened error information file";
		return -4;
	}
	TuringMachine x;
    x.begining(prog, in, out);

}
