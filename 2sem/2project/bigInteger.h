#pragma once
#pragma once
#include <iostream>
#include<string>


unsigned long long int _pow(unsigned long long int x, unsigned int y);
int lenInt(int x);
int lenStr(std::string str);
//template <typename T>
//int Len(T x)
//{
//	int count = 0;
//	while (x)
//	{
//		x /= 10;
//		++count;
//	}
//	return count;
//}



class BigInteger
{
	unsigned int* num;
	int len;
	bool sign = false;


	unsigned int* getNum();
public:
	BigInteger();
	BigInteger(int& x);
	BigInteger(long int& x);
	BigInteger(long long int& x);
	BigInteger(std::string const& str);
	BigInteger(BigInteger const& x): num(x.num), len(x.len), sign(x.sign) {};
	BigInteger(BigInteger&& x): num(std::move(x.num)), len(std::move(x.len)), sign(std::move(x.sign)) {};



	BigInteger& operator=(BigInteger&& x);
	BigInteger& operator=(BigInteger& x);


	const bool operator>(BigInteger& x);
	const bool operator<(BigInteger& x);

	BigInteger& operator+(BigInteger& x);


	~BigInteger()
	{
		if (num)
		{
			delete[] num;
			len = 0;
			sign = false;
		}
	};


	void print();



};

