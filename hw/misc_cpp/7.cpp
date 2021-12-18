//Задача 7. Дана окружность с целочисленным радиусом R<10^6. Посчитать число точек с целочисленными координатами, лежащих внутри окружности, в том числе и находящихся на границе окружности.
#include<cmath>
#include <iostream>
int main() {
	setlocale(LC_ALL, "russian");
	double R;
	std::cin >> R;
	double sum = 0;
	for (double y = 1.; y <= R; y +=1.)
	{
		for (double x = 1.; x <= R; x +=1.)
		{
			if ((x * x + y * y) <= R * R)
			{
				++sum;
			}
		}
	}
    sum*=4;
    sum+=4*R+1;
	std::cout << sum;
}
