#include"boolexpr.h"
#include<cmath>
#include<vector>
bool inFormula(const std::string(&f),const std::string(&x))
{
	int flag = 0, j = 0;
	int i = 0;
	for (; i < f.length(); ++i)
	{
		if (flag)
		{
			if (++j < x.length())
			{
				if ((f[i] != x[j]))
				{
					flag = 0;
					j = 0;
				}
			}
			else return 1;
		}
		if (f[i] == x[0]) flag = 1;

	}
	if ((j == x.length() - 1)&&(x[j]==f[f.length()-1])) return 1;
	return 0;
}

BooleanExpression::BooleanExpression(int& counter, char** (&x), int(&countX))
{
	max = countX;
	count = counter;
	F = new Formula[counter];
	for (int i = 0; i < count; ++i)
	{
		F[i] = Formula(x[i]);
	}
}
BooleanExpression::BooleanExpression(const BooleanExpression& x)
{
	max = x.max;
	count = x.count;
	F = new Formula[count];
	for (int i = 0; i < count; ++i)F[i] = x.F[i];
}

std::string toBin(int x,const int &max)
{
	int i = max;
	std::string res = std::string(i,'0');
	int mult=1;
	int resInt = 0;
	while (x)
	{
		resInt += (x % 2) * mult;
		mult *= 10;
		x /= 2;
	}//10
	while (resInt)
	{
		res[--i] = resInt % 10+'0';
		resInt /= 10;
	}
	return res;
}
void BooleanExpression::truthTabel()
{
	for (int I = 0; I < count; ++I)
	{
		if (max == 1) std::cout << F[I].str()<<" = "<<F[I].calc()<<std::endl;
		else
		{
			auto iter = global::Workspace.begin();
			while (iter != global::Workspace.end())
			{
				std::cout << iter.now->data.getStr();
				std::cout << '\t';

				iter++;
			}

			std::cout << F[I].str();
			std::cout << std::endl;
			int maxBin = pow(2, max);
			for (int i = 0; i < maxBin; ++i)//101010
			{
				std::string str = toBin(i, max);
				auto iter1 = global::Workspace.begin();
				int j = 0;
				while (iter1 != global::Workspace.end())
				{
					std::cout << str[j] << '\t';

					if (str[j++] - '0')
						iter1.now->data.makeTrue();
					else iter1.now->data.makeFalse();

	
					++iter1;

				}

				bool result = F[I].calc();
				std::cout << result << std::endl;
			}
		}
		std::cout << std::endl;
	}
}

bool BooleanExpression::_calc(const int &i)
{
	F[i]._calc();
	return 0;
}

void BooleanExpression::cnf(std::ofstream &out)
{
	for (int I = 0; I < count; ++I)
	{

		int f = 0;

		out << F[I].str() << " = ";
		int maxBin = pow(2, max);
		for (int i = 0; i < maxBin; ++i)//101010
		{
			std::string str = toBin(i, max);
			auto iter1 = global::Workspace.begin();
			int j = 0;

			while (iter1 != global::Workspace.end())
			{
				//std::cout << str[j] << '\t';

				if (str[j++] - '0')
					iter1.now->data.makeTrue();
				else iter1.now->data.makeFalse();


				iter1++;

			}
			


			bool result = F[I]._calc();
			

			if (!result)
			{
				if(f) out << " & (";
				else
				{
					out << "(";
					f = 1;
				}
				auto iter2 = global::Workspace.begin();
				while (iter2 != global::Workspace.end())
				{
					if (iter2.now->data.getValue()) out << "~" << iter2.now->data.getStr();
					else out<< iter2.now->data.getStr();

					iter2++;

					if(iter2 != global::Workspace.end()) out << " v ";


				}
				out << ")";
			}
		}
		out << std::endl;
	}
	out << std::endl;
}
void BooleanExpression::dnf(std::ofstream& out)
{
	for (int I = 0; I < count; ++I)
	{

		int f = 0;
		out << F[I].str() << " = ";
		int maxBin = pow(2, max);
		for (int i = 0; i < maxBin; ++i)//101010
		{
			std::string str = toBin(i, max);
			auto iter1 = global::Workspace.begin();
			int j = 0;

			while (iter1 != global::Workspace.end())
			{

				if (str[j++] - '0')
					iter1.now->data.makeTrue();
				else iter1.now->data.makeFalse();


				iter1++;

			}





			bool result = F[I]._calc();



			if (result)
			{
				if(f) out << " v (";
				else
				{
					out << "(";
					f = 1;
				}
				auto iter2 = global::Workspace.begin();
				while (iter2 != global::Workspace.end())
				{
					if (iter2.now->data.getValue()) out << iter2.now->data.getStr();
					else out << "~" << iter2.now->data.getStr();

					iter2++;

					if (iter2 != global::Workspace.end()) out << " & ";
				}
				out << ")";
			}
		}
		out << std::endl;
	}
	out << std::endl;

}
void BooleanExpression::zheg(std::ofstream& out)
{
	for (int I = 0; I < count; ++I)
	{
		out << F[I].str() << " = ";
		int maxBin = pow(2, max);

		std::vector<bool> first(maxBin);
		std::vector<bool> second(maxBin - 1);
		bool* result = new bool[maxBin];

		std::string str;

		for (int i = 0; i < maxBin; ++i)//101010
		{
			str = toBin(i, max);
			auto iter1 = global::Workspace.begin();
			int j = 0;

			while (iter1 != global::Workspace.end())
			{
				if (str[j++] - '0')
					iter1.now->data.makeTrue();
				else iter1.now->data.makeFalse();


				iter1++;

			}
			
			// 1 0 0 1
			//  1 0 1
			//   1 1 
			//    0

			first[i] = F[I]._calc();
		}

		result[0] = first[0];
		int c = 1;
		while (first.size() > 1)
		{
			
			for (int j = 0; j < first.size() - 1; ++j)
			{
				second[j] = (first[j] + first[j + 1]) % 2;
			}
			result[c++] = second[0];
			first = second;
			second.pop_back();
		}

		int f = 0;
		int flag = 0;

		for (int i = 0; i < maxBin; ++i)
		{
			int j = 0;
			auto iter2 = global::Workspace.begin();
			std::string str = toBin(i, max);
			while (iter2 != global::Workspace.end())
			{
				if (str[j++] - '0')
					iter2.now->data.makeTrue();
				else iter2.now->data.makeFalse();


				iter2++;
			}


			if (result[i])
			{

				auto iter3 = global::Workspace.begin();
				while (iter3 != global::Workspace.end())
				{
					if (iter3.now->data.getValue())
					{
						if (f) std::cout << " + ";
						out<< iter3.now->data.getStr();
						flag = 1;
						f = 1;
					}
					iter3++;
				}
				if (!flag)
				{
					
					if(f) out << " + 1";
					else out << "1";
					f = 1;
				}
			}
		}
		out << std::endl;
	}
	out << std::endl;
}

bool BooleanExpression::isFull(std::ofstream& out)
{
	bool x1 = isSavingZero();
	bool x2 = isSavingOne();
	bool x3 = isSelfSecond();
	bool x4 = isLinear();
	bool x5 = isMonotonous();
	bool result = (x1 && x2 && x3 && x4 && x5);
	std::cout << x1 << x2 <<x3 << x4 << x5;
	//out <<" "<<result;
	out<< ((result)?"yes" : "no");
	std::cout << ((result) ? "yes" : "no");
	return result;
}
bool BooleanExpression::isSavingZero()
{
	bool result=0;
	for (int i = 0; i < count; ++i)
	{
		auto iter1 = global::Workspace.begin();
		while (iter1 != global::Workspace.end())
		{
			iter1.now->data.makeFalse();

			iter1++;
		}
		result = F[i]._calc();

		if (result)
		{
			//std::cout << 1;
			return 1;
		}
	}
	//std::cout << 0;

	return 0;
}
bool BooleanExpression::isSavingOne()
{
	bool result = 1;
	for (int i = 0; i < count; ++i)
	{
		auto iter1 = global::Workspace.begin();
		while (iter1 != global::Workspace.end())
		{
			iter1.now->data.makeTrue();

			++iter1;
		}
		result = F[i]._calc();
		std::cout << " " << result << " ";
		if (!result)
		{
			//std::cout << 1;
			return 1;
		}
	}
	//std::cout << 0;
	return 0;
}
bool BooleanExpression::isSelfSecond()
{
	//f(x1, x2, x3) = ~f(~x1, ~x2, ~x3)

	std::string str2;
	std::string str1;

	for (int I = 0; I < count; ++I)
	{
		int maxBin = pow(2, max);
		for (int i = 0; i < maxBin / 2; ++i)//101010
		{
			str1 = toBin(i, max);
			str2 = toBin(maxBin - i - 1, max);


			//1 строка
			auto iter1 = global::Workspace.begin();
			int j = 0;

			while (iter1 != global::Workspace.end())
			{
				if (str1[j++] - '0')
					iter1.now->data.makeTrue();
				else iter1.now->data.makeFalse();


				iter1++;

			}

			bool result1 = F[I]._calc();


			//2 строка
			auto iter2 = global::Workspace.begin();
			j = 0;

			while (iter2 != global::Workspace.end())
			{
				if (str2[j++] - '0')
					iter2.now->data.makeTrue();
				else iter2.now->data.makeFalse();


				iter2++;

			}

			bool result2 = F[I]._calc();




			if (result1 == result2)
			{
				//std::cout << 1;
				return 1;
			}

		}
	}
	//std::cout << 0;
	return 0;

}
bool BooleanExpression::isLinear()
{
	for (int I = 0; I < count; ++I)
	{
		//std::cout << F[I].str() << " = ";
		int maxBin = pow(2, max);

		std::vector<bool> first(maxBin);
		std::vector<bool> second(maxBin - 1);
		bool* result = new bool[maxBin];

		std::string str;

		for (int i = 0; i < maxBin; ++i)//101010
		{
			str = toBin(i, max);
			auto iter1 = global::Workspace.begin();
			int j = 0;

			while (iter1 != global::Workspace.end())
			{
				if (str[j++] - '0')
					iter1.now->data.makeTrue();
				else iter1.now->data.makeFalse();


				iter1++;

			}

			// 1 0 0 1
			//  1 0 1
			//   1 1 
			//    0

			first[i] = F[I]._calc();
		}

		result[0] = first[0];
		int c = 1;
		while (first.size() > 1)
		{

			for (int j = 0; j < first.size() - 1; ++j)
			{
				second[j] = (first[j] + first[j + 1]) % 2;
			}
			result[c++] = second[0];
			first = second;
			second.pop_back();
		}

		int f = 0;
		int flag = 0;
		std::string formula = F[I].str();

		for (int i = 0; i < maxBin; ++i)
		{
			int j = 0;
			auto iter2 = global::Workspace.begin();
			std::string str = toBin(i, max);
			while (iter2 != global::Workspace.end())
			{
				if (str[j++] - '0')
					iter2.now->data.makeTrue();
				else iter2.now->data.makeFalse();


				iter2++;
			}


			if (result[i])
			{
				f = 0;
				auto iter3 = global::Workspace.begin();
				while (iter3 != global::Workspace.end())
				{
					if ((iter3.now->data.getValue()) && (inFormula(formula, iter3.now->data.getStr())))
					{
						++f;
					}
					iter3++;
				}
				if (f >= 2)
				{
					//std::cout << 1;
					return 1;
				}
			}

		}
	}
	//std::cout << 0;
	return 0;
	std::cout << std::endl;
}
bool BooleanExpression::isMonotonous()
{

	for (int I = 0; I < count; ++I)
	{
		bool prevRes = 0;
		int f = 0;
		int maxBin = pow(2, max);

		for (int i = 0; i < maxBin; ++i)//101010
		{
			std::string str = toBin(i, max);
			auto iter1 = global::Workspace.begin();
			int j = 0;

			while (iter1 != global::Workspace.end())
			{
				//std::cout << str[j] << '\t';

				if (str[j++] - '0')
					iter1.now->data.makeTrue();
				else iter1.now->data.makeFalse();


				iter1++;

			}



			bool result = F[I]._calc();
			if (prevRes > result)
			{
				//std::cout << 1;
				return 1;
			}
			prevRes = result;
		}
	}
	//std::cout << 0;
	return 0;

}

