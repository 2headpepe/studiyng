//Задача 4. Вычислить сумму 1+x+x^2+x^3+... в заданной точке до тех пор, пока значение очередного слагаемого по модулю больше заданного eps. Сравнить результат с 1/(1-x). x подается в диапазоне (-1,1).
#include<cmath>
#include <iostream>
int main() {
	setlocale(LC_ALL, "russian");
	float x, eps;
	std::cout << "Введите х,eps\n";
	std::cin >> x >> eps;
	float sum = 0, curr = 1;
	while (abs(curr) >= eps)
	{
		sum += curr;
		curr *= x;
	}
	std::cout << sum << "  " << 1 / (1 - x);
}
