#include"biginteger.h"


void toNormal(BigInteger& X)
{
	int i = 0;
	while ((X.data[i] == 0) && (X.data.size() > 1))
		X.data.erase(X.data.begin(), X.data.begin()+1);
}

BigInteger::BigInteger(const std::string& number)
{
	int i = 0;
	if (number[0] == '-')
	{
		++i;
		sign = false;
	}
	for (; i < number.length(); ++i)
	{
		if ((number[i] > 57) || (number[i] < 48)) throw std::invalid_argument("((");
		data.push_back(number[i] - 48);
	}
	toNormal(*this);
}
BigInteger::BigInteger()
{
	sign = true;
	data = {};
}
BigInteger::BigInteger(const long long number) 
	:BigInteger(std::to_string(number))
{
	
}
BigInteger::BigInteger(const BigInteger& X):
	data(X.data),sign(X.sign) {}
BigInteger::BigInteger(const BigInteger&& X) :
	data(std::move(X.data)), sign(std::move(X.sign)) {}

BigInteger& BigInteger::operator=(const BigInteger&& X)
{
	data = std::move(X.data);
	sign = std::move(X.sign);
	return *this;
}
BigInteger& BigInteger::operator=(const BigInteger& X)
{
	data = X.data;
	sign = X.sign;
	return *this;
}
bool BigInteger::operator!=(const BigInteger& X) const
{
	return !(*this == X);
}
bool BigInteger::operator==(const BigInteger& X) const
{
	if (sign == X.sign)
	{
		return (data == X.data);
	}
	else if ((*this == 0) && (X == 0)) return 1;
	else return 0;
}
bool BigInteger::operator>(const BigInteger& X) const
{
	if((sign)&&(!X.sign)&&(X.data.size())) return 1;
	if ((!sign) && (X.sign)) return 0;
	if (sign)
	{
		if (data.size() > X.data.size()) return 1;
		if (data.size() < X.data.size()) return 0;
		for (int i = 0; i < data.size(); ++i)
		{
			if (data[i] > X.data[i]) return 1;
			if (data[i] < X.data[i]) return 0;
		}
		return 0;
	}
	else
	{
		if (data.size() < X.data.size()) return 1;
		if (data.size() > X.data.size()) return 0;
		for (int i = 0; i < data.size(); ++i)
		{
			if (data[i] < X.data[i]) return 1;
			if (data[i] > X.data[i]) return 0;
		}
		return 0;
	}
}
bool BigInteger::operator>=(const BigInteger& X) const
{
	return ((*this == X) || (*this > X));
}
bool BigInteger::operator<(const BigInteger& X) const
{
	return (!(*this > X)) && (!(*this == X));
}
bool BigInteger::operator<=(const BigInteger& X) const
{
	return ((*this < X) || (*this == X));
}

int BigInteger::digAt(const int i) const
{
	if ((i >= data.size()) || (i < 0)) return 0;
	else return data[i];
}
void BigInteger::reverse()
{
	std::vector<unsigned int> tmp(data.size());
	for (int i = data.size() - 1; i >= 0; --i) tmp[-i + data.size() - 1] = data[i];
	data = tmp;
}
const BigInteger operator+(const int& x, const BigInteger& X)
{
	BigInteger _x{ x };
	return _x + X;
}
const BigInteger BigInteger::operator+(const BigInteger& X) const
{
	BigInteger res{};
	if (sign == X.sign)
	{
		res.sign = sign;
		
		int i = data.size() - 1;
		int j = X.data.size() - 1;
		int tmpSum = 0;
		int nxtDig=0;
		while ((j>=0)||(i>=0))
		{
			tmpSum = digAt(i) + X.digAt(j) + nxtDig;
			res.data.push_back(tmpSum % 10);
			nxtDig = tmpSum / 10;

			--j;
			--i;
		}
		if (nxtDig) res.data.push_back(nxtDig);
		res.reverse();
	}
	else
	{
		BigInteger first = *this;
		first.sign = true;

		BigInteger second = X;
		first.sign = true;
		if (first > second)
		{
			res.sign = sign;
			int i = data.size() - 1;
			int j = X.data.size() - 1;
			int tmpDif = 0;
			int nxtDig=0;

			while ((i >= 0)||(j>=0))
			{
				tmpDif = digAt(i) - X.digAt(j)-nxtDig;
				if (tmpDif < 0)
				{
					nxtDig = 1;
					tmpDif += 10;
				}
				else nxtDig = 0;
				res.data.push_back(tmpDif % 10);

				--i;
				--j;
			}
			res.reverse();
		}
		else
		{
			res.sign = !sign;
			int i = data.size() - 1;
			int j = X.data.size() - 1;
			int tmpDif = 0;
			int nxtDig = 0;

			while ((i >= 0) || (j >= 0))
			{
				tmpDif = -digAt(i) + X.digAt(j) - nxtDig;
				if (tmpDif < 0)
				{
					nxtDig = 1;
					tmpDif += 10;
				}
				else nxtDig = 0;
				res.data.push_back(tmpDif % 10);

				--i;
				--j;
			}
			res.reverse();
		}
		toNormal(res);
	}
	return res;
}
BigInteger& BigInteger::operator+=(const BigInteger& X) 
{
	*this = *this + X;
	return *this;
}
const BigInteger BigInteger::operator-(const BigInteger& X) const
{
	BigInteger x = X;
	x.sign = !X.sign;
	return (*this + x);
}
BigInteger& BigInteger::operator-=(const BigInteger& X)
{
	*this = *this - X;
	return *this;
}

BigInteger BigInteger::multX(const unsigned int &x) const
{
	BigInteger res{};
	res.sign = true;
	int i = data.size() - 1;
	int nxtDig = 0;
	int tmpMult=0;
	for (; i >= 0; --i)
	{
		tmpMult = digAt(i) * x + nxtDig;
		res.data.push_back(tmpMult % 10);
		nxtDig = tmpMult / 10;
	}
	if (nxtDig) res.data.push_back(nxtDig);
	res.reverse();
	return res;
}
const BigInteger BigInteger::operator*(const BigInteger& X) const
{
	BigInteger res{};
	BigInteger dig{ };
	int i = X.data.size() - 1;
	int count = 0;
 	for (; i >= 0; --i)
	{
		int tmpDig = X.digAt(i);
		dig= multX(tmpDig);
		dig.data.insert(dig.data.end(), count++, 0);
		res += dig;
	}
	
	if (sign != X.sign) res.sign = false;
	else res.sign = true;

	return res;
}
BigInteger& BigInteger::operator*=(const BigInteger& X)
{
	*this = *this * X;
	
	return *this;
}
const BigInteger BigInteger::operator/(const BigInteger& X) const
{
	BigInteger res{};
	res.sign = (X.sign == sign) ? true : false;
	BigInteger buf{};

	BigInteger _X = X;
	if (!X.sign) _X.sign = true;
	if (X == 0) throw "Делить на ноль не будем";
	int tmpDig;
	int i = 0;
	

	for (; i < data.size(); ++i)
	{
		while ((buf < _X) && (i < data.size()))
		{
			buf.data.push_back(data[i]);
			++i;
		}
		toNormal(buf);	
		tmpDig=0;
		while (buf >= _X)
		{
			buf -= _X;
			++tmpDig;
		}
		res.data.push_back(tmpDig);
		while ((buf < _X) && (i < data.size()))
		{
			res.data.push_back(0);
			buf.data.push_back(data[i]);
			++i;
		}
		toNormal(res);
	}
	return res;
}
BigInteger& BigInteger::operator/=(const BigInteger& X)
{
	*this = *this / X;

	return *this;

}
BigInteger& BigInteger::operator-()
{
	BigInteger _X = *this;
	_X.sign = !sign;
	return _X;
}
BigInteger& BigInteger::operator+()
{
	return (*this);
}

const BigInteger& operator++(BigInteger& X)
{
	X = X + 1;
	return X;
}
const BigInteger operator++(BigInteger& X, int) {
	BigInteger y(X);
	X = X + 1;
	return y;
}

const BigInteger& operator--(BigInteger& X) {
	X = X - 1;
	return X;
}
const BigInteger operator--(BigInteger& X, int) {
	BigInteger y(X);
	X = X - 1;
	return y;
}

BigInteger& BigInteger::operator<<(const int& x)
{
	BigInteger res(*this);
	for (int i = 0; i < x; ++i) res *= 2;
	return res;
}
BigInteger& BigInteger::operator>>(const int& x)
{
	BigInteger res(*this);
	for (int i = 0; i < x; ++i) res /= 2;
	return res;
}

BigInteger& BigInteger::operator&(const BigInteger& X)
{
	BigInteger first(*this);
	BigInteger second(X);
	BigInteger res{};
	while ((first.data.size() > 0) || (second.data.size() > 0))
	{
		if ((first.data[data.size() - 1] % 2) && (second.data[data.size() - 1] % 2)) res.data.push_back(1);
		else res.data.push_back(0);

		first /= 2;
		second /= 2;
	}
	res.reverse();
	return res;
}
BigInteger& BigInteger::operator|(const BigInteger& X)
{
	BigInteger first(*this);
	BigInteger second(X);
	BigInteger res{};
	while ((first.data.size() > 0) || (second.data.size() > 0))
	{
		if (!(first.data[data.size() - 1] % 2) && !(second.data[data.size() - 1] % 2)) res.data.push_back(0);
		else res.data.push_back(1);

		first /= 2;
		second /= 2;
	}
	res.reverse();
	return res;
}
BigInteger& BigInteger::operator^(const BigInteger& X)
{
	BigInteger first(*this);
	BigInteger second(X);
	BigInteger res{};
	while ((first.data.size() > 0) || (second.data.size() > 0))
	{
		if (!(first.data[data.size() - 1] % 2) && !(second.data[data.size() - 1] % 2)) res.data.push_back(0);
		if ((first.data[data.size() - 1] % 2) && (second.data[data.size() - 1] % 2)) res.data.push_back(0);
		else res.data.push_back(1);

		first /= 2;
		second /= 2;
	}
	res.reverse();
	return res;
}
BigInteger& BigInteger::operator~()
{
	BigInteger first(*this);
	BigInteger res{};
	while ((first.data.size() > 0))
	{
		res.data.push_back(first.data[data.size() - 1] % 2);
		first /= 2;
	}
	res.reverse();
	return res;
}


std::string to_string(const BigInteger& x)
{
	std::string str;
	if (!x.sign)
		str += "-";
	for (unsigned int i = 0; i < x.data.size(); i++)
		str += std::to_string(x.digAt(i));
	return str;
}
