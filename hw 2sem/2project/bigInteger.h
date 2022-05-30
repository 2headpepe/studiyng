#pragma once
#include<iostream>
#include<vector>
#include<string>
class BigInteger {
public:
	BigInteger();
	BigInteger(const long long number);
	BigInteger(const std::string &number);
	BigInteger(const BigInteger& X);
	BigInteger(const BigInteger&& X);
	BigInteger& operator=(const BigInteger& X);
	BigInteger& operator=(const BigInteger&& X);
	bool operator>(const BigInteger& X) const;
	bool operator>=(const BigInteger& X) const;
	bool operator<(const BigInteger& X) const;
	bool operator<=(const BigInteger& X) const;
	bool operator==(const BigInteger& X) const;
	bool operator!=(const BigInteger& X) const;
	const BigInteger operator+(const BigInteger& X) const;
	BigInteger& operator+=(const BigInteger& X);
	const BigInteger operator-(const BigInteger& X) const;
	BigInteger& operator-=(const BigInteger& X);
	const BigInteger operator*(const BigInteger& X) const;
	BigInteger& operator*=(const BigInteger& X);
	const BigInteger operator/(const BigInteger& X) const;
	BigInteger& operator/=(const BigInteger& X);
	BigInteger& operator-();
	BigInteger& operator+();
	friend const BigInteger& operator++(BigInteger& X);
	friend const BigInteger operator++(BigInteger& X, int);
	friend const BigInteger& operator--(BigInteger& X);
	friend const BigInteger operator--(BigInteger& X, int);
	friend const BigInteger operator+(const int& x, const BigInteger& X);
	BigInteger& operator<<(const int& x);
	BigInteger& operator>>(const int& x);
	BigInteger& operator&(const BigInteger& x);
	BigInteger& operator|(const BigInteger& x);
	BigInteger& operator^(const BigInteger& x);
	BigInteger& operator~();
	friend std::string to_string(const BigInteger& x);
private:
	friend void toNormal(BigInteger& X);
	BigInteger multX(const unsigned int &x) const;
	void reverse();

	int digAt(const int i) const;

	std::vector<unsigned int> data;
	bool sign=true;
};
