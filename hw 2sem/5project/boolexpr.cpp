#include"boolexpr.h"
#include<cmath>
#include<vector>
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

void BooleanExpression::cnf()
{
	for (int I = 0; I < count; ++I)
	{

		int f = 0;

		std::cout << F[I].str() << " = ";
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
				if(f) std::cout << " & (";
				else
				{
					std::cout << "(";
					f = 1;
				}
				auto iter2 = global::Workspace.begin();
				while (iter2 != global::Workspace.end())
				{
					if (iter2.now->data.getValue()) std::cout << "~" << iter2.now->data.getStr();
					else std::cout<< iter2.now->data.getStr();

					iter2++;

					if(iter2 != global::Workspace.end()) std::cout << " v ";


				}
				std::cout << ")";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void BooleanExpression::dnf()
{
	for (int I = 0; I < count; ++I)
	{

		int f = 0;
		std::cout << F[I].str() << " = ";
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



			if (result)
			{
				if(f) std::cout << " v (";
				else
				{
					std::cout << "(";
					f = 1;
				}
				auto iter2 = global::Workspace.begin();
				while (iter2 != global::Workspace.end())
				{
					if (iter2.now->data.getValue()) std::cout << iter2.now->data.getStr();
					else std::cout << "~" << iter2.now->data.getStr();

					iter2++;

					if (iter2 != global::Workspace.end()) std::cout << " & ";
				}
				std::cout << ")";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}
void BooleanExpression::zheg()
{
	for (int I = 0; I < count; ++I)
	{
		std::cout << F[I].str() << " = ";
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
						if (f) std::cout << " + " << iter3.now->data.getStr();
						else std::cout << iter3.now->data.getStr();
						flag = 1;
						f = 1;
					}
					iter3++;
				}
				if (!flag)
				{
					
					if(f) std::cout << " + 1";
					else std::cout << "1";
					f = 1;
				}
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool BooleanExpression::isFull()
{
	bool result = (isSavingZero() && isSavingOne() && isSelfSecond() && isLinear() && isMonotonous());
	return result;
}
bool BooleanExpression::isSavingZero()
{
	bool* result = new bool[count];
	for (int i = 0; i < count; ++i)
	{
		auto iter1 = global::Workspace.begin();
		while (iter1 != global::Workspace.end())
		{
			iter1.now->data.makeFalse();

			iter1++;
		}
		result[i] = F[i]._calc();
		if (result[i])
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
	bool* result = new bool[count];
	for (int i = 0; i < count; ++i)
	{
		auto iter1 = global::Workspace.begin();
		while (iter1 != global::Workspace.end())
		{
			iter1.now->data.makeTrue();

			iter1++;
		}
		result[i] = F[i]._calc();
		if (!result[i])
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

		for (int i = 0; i < maxBin; ++i)
		{
			int j = 0;
			auto iter2 = global::Workspace.begin();
			//std::string str = toBin(i, max);
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
					if (iter3.now->data.getValue())
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
	bool prevRes=0;
	for (int I = 0; I < count; ++I)
	{
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
