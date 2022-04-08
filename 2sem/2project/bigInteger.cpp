#include "biginteger.h"

int lenInt(int x)
{
	int count = 0;
	while (x)
	{
		x /= 10;
		++count;
	}
	return count;
}
unsigned long long int _pow(unsigned long long int x, unsigned int y)
{
	if (y == 0) return 1;
	unsigned long long int def = x;
	for (unsigned int i = 1; i < y; ++i)
	{
		x *= def;
	}
	return x;
}

//конструкторы
BigInteger::BigInteger() {
	num = new unsigned int[1];
	num[0] = 0;
	len = 1;
}
BigInteger::BigInteger(int& x)
{
	len = 1;
	num = new unsigned int[len];
	if (x < 0)
	{
		sign = true;
		num[0] = -x;
	}
	else num[0] = x;
}
BigInteger::BigInteger(long int& x)
{
	len = 1;
	num = new unsigned int[len];
	if (x < 0)
	{
		sign = true;
		num[0] = -x;
	}
	else num[0] = x;
}
BigInteger::BigInteger(long long int& x) {
	len = lenInt(x) / 9 + 1;
	num = new unsigned int[len];
	int i = 0;//lenint(x) - 1;
	//unsigned long long int digit = 4294967295;
	//unsigned long long int digitdec = _pow(10, 10);

	if (x < 0)
	{
		sign = true;
		x = -x;
	}

	for (int i = 0; i < len; ++i) num[i] = 0;
	int dig = 1;
	int count = len-1;
	while (x)
	{
		
		for (int i = 0; i < 9; ++i)
		{
			num[count] += x % 10 * dig;
			dig *= 10;
		}
		count++;
		dig = 1;
	}

}
BigInteger::BigInteger(std::string const& str) {
	int lenStr = str.size(),number, j, end, dig = 1;
	if (str[0] == '-')
	{
		--lenStr;
		sign = true;
		j=lenStr;
		end = 1;
	}
	else
	{
		j = lenStr - 1;
		end = 0;
	}
	len = lenStr / 9 + 1;
	number = len - 1;

	num = new unsigned int[len];
	for (int i = 0; i < len; ++i) num[i] = 0;

	//int begin = lenStr - 1;
	//int end = (begin > 10) ? begin - 9 : 0;
	int i = 0,count=len-1;
	for (; j >=end; --j)
	{
		if (i < 9) {
			num[count] += dig * (str[j] - 48);
			dig *= 10;
			++i;
		}
		else
		{
			count--;
			dig = 1;
			num[count] += dig * (str[j] - 48);
			dig = 10;
			i = 1;
		}
	}
}



//операторы
BigInteger& BigInteger::operator=(BigInteger&& x)
{
	if (this != &x) {
		num = std::move(x.num);
		len = std::move(x.len);
		sign = std::move(x.sign);
	}
	return *this;
}
BigInteger& BigInteger::operator=(BigInteger& x)
{
	num = x.num;
	len = x.len;
	sign = x.sign;
	return *this;
}

const bool  BigInteger::operator>(BigInteger& x)
{
	if (len > x.len) return 1;
	if (len < x.len) return 0;

	for (int i = 0; i < len; ++i)
	{
		if (num[i] > x.num[i]) return 1;
		if (num[i] < x.num[i]) return 0;
	}
	return 0;

}
const bool  BigInteger::operator<(BigInteger& x)
{
	if (len < x.len) return 1;
	if (len > x.len) return 0;

	for (int i = 0; i < len; ++i)
	{
		if (num[i] < x.num[i]) return 1;
		if (num[i] > x.num[i]) return 0;
	}
	return 0;

}

//операции
BigInteger& BigInteger::operator+(BigInteger& x)
{
	unsigned long long int digitdec = _pow(10, 9);
	unsigned long long int bord = 999999999;

	unsigned long long int tmp1 = 0, tmp2 = 0;
	unsigned long long int tmp3 = 0;

	int lenTmp = len;
	if (len == x.len)
	{	
		if (x.sign == sign)
		{


			for (int i = len-1; i>=0; --i)
			{
				tmp1 = num[i];
				tmp2 = x.num[i];

				tmp3 = tmp1 % digitdec + tmp2 % digitdec;
				if ((tmp3 / digitdec + tmp1 / digitdec + tmp2 / digitdec))
				{
					int j = i;


						while ((num[j - 1] == bord) && (x.num[j - 1] == bord) && (j >= 0))
						{
							j--;
							num[j] = 0;
						}
						if (j < 0) lenTmp++;
						else if (num[j] != bord) ++num[j];
						else ++x.num[j];

					tmp3 += (tmp3 / digitdec + tmp1 / digitdec + tmp2 / digitdec - 10) * digitdec;
				}
				else tmp3 += (tmp3 / digitdec + tmp1 / digitdec + tmp2 / digitdec) * digitdec;

				num[i] = tmp3;
				/*if ((x.num[i] / digitdec + num[i] / digitdec) < 9)
					tmp.num[i + 1] = x.num[i] + num[i];
				else
				{
					tmp.num[i + 1] = (x.num[i] % digitdec + num[i] % digitdec) + (x.num[i] / digitdec + num[i] - 10) * digitdec;
					tmp.num[i]++;
				}*/
			}

			

			if (lenTmp > len)
			{
				BigInteger tmp;
				tmp.num = new unsigned int[lenTmp];
				tmp.sign = sign;
				tmp.len = lenTmp;
				num[0] = 1;
				for (int i = 1; i < tmp.len; ++i) tmp.num[i] = num[i - 1];
				return tmp;
			}
			else return *this;

			
		}
		else
		{
			if (*this > x)
			{
				for (int i = len; i >= 0; --i)
				{
					tmp1 = num[i];
					tmp2 = x.num[i];
					if (tmp1 > tmp2) num[i] -= tmp2;
					else if (tmp1 < tmp2)
					{
						num[i] = tmp1 + (10 - tmp2 / digitdec) * digitdec - tmp2 % digitdec;
						--num[i - 1];
					}
					else num[i] = 0;

				}

				int j = 0;
				while ((j < len) && (num[j] == 0)) --lenTmp;

				if (lenTmp < len)
				{
					BigInteger tmp;
					tmp.num = new unsigned int[lenTmp];
					tmp.sign = sign;
					tmp.len = lenTmp;
					for (int i = 0; i < lenTmp; ++i) tmp.num[i] = num[i + len - lenTmp];
					return tmp;
				}
				else return *this;
			}
			else if(*this < x)
			{
				for (int i = len; i >= 0; --i)
				{
					tmp1 = num[i];
					tmp2 = x.num[i];
					if (tmp2 > tmp1) num[i] -= tmp1;
					else if (tmp2 < tmp1)
					{
						num[i] = tmp2 + (10 - tmp1 / digitdec) * digitdec - tmp1 % digitdec;
						--num[i - 1];
					}
					else num[i] = 0;

				}

				int j = 0;
				while ((j < len) && (num[j] == 0)) --lenTmp;

				if (lenTmp < len)
				{
					BigInteger tmp;
					tmp.num = new unsigned int[lenTmp];
					tmp.sign = !sign;
					tmp.len = lenTmp;
					for (int i = 0; i < lenTmp; ++i) tmp.num[i] = num[i + len - lenTmp];

					return tmp;
				}
				else return *this;
			}
			else
			{
				BigInteger tmp = {};
				return tmp;
			}
			/*int i = 0;
			int lenTmp = len;
			while ((num[i] == x.num[i])&&(i<len))
			{
				++i;
				len--;
			}
			if (num[i] > x.num[i]) tmp.sign = sign;
			
			tmp.num = new unsigned int[lenTmp];
			tmp.len = lenTmp;
			for (int i = 0; i < tmp.len; ++i) tmp.num = 0;

			for (int j = len-1; j >= i; ++j)
			{
				if(num[j]>x.num[j])
					tmp.num[j - i] = num[j] - x.num[j];
				else
				{

					--num[j - 1];
					tmp.num[j - i] = num[j] + (10-x.num[j]/digitdec)*digitdec- x.num[j] % digitdec;

				}
			}*/
		}
	}
	else if (len>x.len)
	{
		int d = len - x.len;
		if (sign == x.sign)
		{
			for (int i = len - 1; i >= d; --i)
			{
				tmp1 = num[i];
				tmp2 = x.num[i-d];

				tmp3 = tmp1 % digitdec + tmp2 % digitdec;
				if ((tmp3 / digitdec + tmp1 / digitdec + tmp2 / digitdec))
				{
					int j = i;


					while ((num[j - 1] == bord) && (x.num[j - 1-d] == bord) && (j >= d))
					{
						j--;
						num[j] = 0;
					}
					if(j==d)
					while ((num[j - 1] == bord) && (j >= 0))
					{
						j--;
						num[j] = 0;
					}
					if (j < 0) lenTmp++;
					else if (num[j] != bord) ++num[j];
					else ++x.num[j];

					tmp3 += (tmp3 / digitdec + tmp1 / digitdec + tmp2 / digitdec - 10) * digitdec;
				}
				else tmp3 += (tmp3 / digitdec + tmp1 / digitdec + tmp2 / digitdec) * digitdec;

				num[i] = tmp3;
				/*if ((x.num[i] / digitdec + num[i] / digitdec) < 9)
					tmp.num[i + 1] = x.num[i] + num[i];
				else
				{
					tmp.num[i + 1] = (x.num[i] % digitdec + num[i] % digitdec) + (x.num[i] / digitdec + num[i] - 10) * digitdec;
					tmp.num[i]++;
				}*/
			}
			if (lenTmp > len)
			{
				int j = d - 1;
				while ((j >= 0) && (num[j] == bord)) num[j] = 0;
				if (j < 0)
				{
					BigInteger tmp;
					tmp.num = new unsigned int[lenTmp];
					tmp.sign = sign;
					tmp.len = lenTmp;

					num[0] = 1;
					for (int i = 1; i < tmp.len; ++i) tmp.num[i] = num[i - 1];

					return tmp;
				}
				else
				{
					++num[j];

					BigInteger tmp;
					tmp.num = new unsigned int[--lenTmp];
					tmp.sign = sign;
					tmp.len = lenTmp;

					for (int i = 0; i < len; ++i) tmp.num[i] = num[i];

					return tmp;
				}
			}
			else
			{
				BigInteger tmp;
				tmp.num = new unsigned int[lenTmp];
				tmp.sign = sign;
				tmp.len = lenTmp;

				for (int i = 0; i < tmp.len; ++i) tmp.num[i] = num[i];

				return tmp;
			}
		}
		else 
		{
			for (int i = len - 1; i >= d; --i)
			{
				tmp1 = num[i];
				tmp2 = x.num[i];
				if (tmp1 > tmp2) num[i] -= tmp2;
				else if (tmp1 < tmp2)
				{
					num[i] = tmp1 + (10 - tmp2 / digitdec) * digitdec - tmp2 % digitdec;
					--num[i - 1];
				}
				else num[i] = 0;
			}
			return *this;
			/*tmp.sign = sign;
			tmp.len = len;
			tmp.num = new unsigned int[tmp.len];
			for (int i = 0; i < tmp.len; ++i) tmp.num = 0;


			int d = len - x.len;

			for (int i = len - 1; i >= d; ++i)
			{
				if (num[i] > x.num[i])
					tmp.num[i - d] = num[i] - x.num[i];
				else
				{
					--num[i - 1];
					tmp.num[i - d] = num[i] + (10 - x.num[i] / digitdec) * digitdec - x.num[i] % digitdec;

				}
			}*/
		}

	}
	else if (len < x.len)
	{
		int d = len - x.len;
		if (sign == x.sign)
		{
			for (int i = len - 1; i >= d; --i)
			{
				tmp1 = num[i];
				tmp2 = x.num[i];

				tmp3 = tmp1 % digitdec + tmp2 % digitdec;
				if ((tmp3 / digitdec + tmp1 / digitdec + tmp2 / digitdec))
				{
					int j = i;


					while ((num[j - 1] == bord) && (x.num[j - 1] == bord) && (j >= 0))
					{
						j--;
						num[j] = 0;
					}
					if (j < 0) lenTmp++;
					else if (num[j] != bord) ++num[j];
					else ++x.num[j];

					tmp3 += (tmp3 / digitdec + tmp1 / digitdec + tmp2 / digitdec - 10) * digitdec;
				}
				else tmp3 += (tmp3 / digitdec + tmp1 / digitdec + tmp2 / digitdec) * digitdec;

				num[i] = tmp3;
				/*if ((x.num[i] / digitdec + num[i] / digitdec) < 9)
				tmp.num[i + 1] = x.num[i] + num[i];
			else
			{
				tmp.num[i + 1] = (x.num[i] % digitdec + num[i] % digitdec) + (x.num[i] / digitdec + num[i] - 10) * digitdec;
				tmp.num[i]++;
			}*/
			}
			if (lenTmp > len)
			{
				int j = d - 1;
				while ((j >= 0) && (num[j] == bord)) num[j] = 0;
				if (j < 0)
				{
					BigInteger tmp;
					tmp.num = new unsigned int[lenTmp];
					tmp.sign = sign;
					tmp.len = lenTmp;
	
					num[0] = 1;
					for (int i = 1; i < tmp.len; ++i) tmp.num[i] = num[i - 1];

					return tmp;
				}
				else
				{
					++num[j];

					BigInteger tmp;
					tmp.num = new unsigned int[--lenTmp];
					tmp.sign = sign;
					tmp.len = lenTmp;
	
					for (int i = 0; i < len; ++i) tmp.num[i] = num[i];

					return tmp;
				}
			}
			else
			{
				BigInteger tmp;
				tmp.num = new unsigned int[lenTmp];
				tmp.sign = sign;
				tmp.len = lenTmp;

				for (int i = 0; i < tmp.len; ++i) tmp.num[i] = num[i];
			}
		}
		else
		{
			for (int i = len - 1; i >= d; --i)
			{
				tmp1 = num[i];
				tmp2 = x.num[i];
				if (tmp2 > tmp1) num[i] -= tmp2;
				else if (tmp2 < tmp1)
					{
					num[i] = tmp2 + (10 - tmp1 / digitdec) * digitdec - tmp1 % digitdec;
					--x.num[i - 1];
				}
				else num[i] = 0;
			}
			return *this;
			/*tmp.sign = sign;
		tmp.len = len;
		tmp.num = new unsigned int[tmp.len];
		for (int i = 0; i < tmp.len; ++i) tmp.num = 0;


		int d = len - x.len;

		for (int i = len - 1; i >= d; ++i)
		{
			if (num[i] > x.num[i])
				tmp.num[i - d] = num[i] - x.num[i];
			else
			{
				--num[i - 1];
				tmp.num[i - d] = num[i] + (10 - x.num[i] / digitdec) * digitdec - x.num[i] % digitdec;

			}
		}*/
		}
	}
}



unsigned int* BigInteger::getNum()
{
	return num;
}


void BigInteger::print()
{
	if (sign) std::cout << '-';
	for (int i = 0; i < len; ++i) std::cout << num[i] << "   ";

	std::cout << std::endl << len << std::endl;

}
