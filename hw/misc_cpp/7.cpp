//Задача 7. Дана окружность с целочисленным радиусом R<10^6. Посчитать число точек с целочисленными координатами, лежащих внутри окружности, в том числе и находящихся на границе окружности.
#include<cmath>
#include <iostream>
int main() {
	setlocale(LC_ALL, "russian");
	int R;
	std::cin >> R;
	int sum = 0;
	for (int y = -(int)R; y <= (int)R; y +=1)
	{
		for (int x = -(int)R; x <= (int)R; x +=1)
		{
			if ((x * x + y * y) <= R * R)
			{
				++sum;
			}
		}
	}

	std::cout << sum;
}
