//Задача 2. Посчитать вещественные корни квадратного уравнения ax^2+bx+c=0. На вход подаются коэффициенты a, b, c. Постараться учесть все возможные варианты значений коэффициентов.

#include <iostream>
#include <cmath>
int main() {
	setlocale(LC_ALL, "russian");
	double a, b, c;
	std::cout << "Input a,b,c\n";
	std::cin >> a >> b >> c;
	if(a==0) std::cout << "Уравнение имеет 1 корень: "<<-c/b;
	else
	{
		double d = b * b - 4 * a * c;
		if (d < 0)
		{
			std::cout << "Нет корней";
		}
		else if(d==0)
		{
			std::cout << "Уравнение имеет 1 корень: " << -b / 2 / a;
		}
		else 
		{
			double x1 = (-b + sqrt(d)) / 2 / a;
			double x2 = (-b - sqrt(d)) / 2 / a;
			std::cout << "Уравнение имеет 2 корня: " << x1 << " и " << x2;
		}
	}
}
