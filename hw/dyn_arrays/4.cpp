#include<iostream>
#include<cmath>
double mysqrt(double x, double eps = 1e-6)
{
	float curr = 1.0,A=1.0;
	do
	{
		curr = A;
		A = (curr + x / curr) / 2;
		std::cout << A << " " << curr << std::endl;
	} while (std::abs((curr - A)) > eps);
	return A;
}

int main()
{
	double x, eps;
	std::cin >> x >> eps;
	mysqrt(x,eps);
}
