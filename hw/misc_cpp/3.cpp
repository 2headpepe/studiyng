//Задача 3. На вход подаются координаты точки на плоскости. Проверить, попадает ли она в кольцо, образованное пространством между границей внешней окружности радиуса R и внутренней окружности радиуса r.

#include <iostream>
int main() {
	setlocale(LC_ALL, "russian");
	float x, y,R,r;
	std::cout << "Введите х,у";
	std::cin >> x >> y;
	std::cout << "Введите R,r";
	std::cin >> R >> r;
	int a = x * x + y * y;
	if ((a < R*R) && (a > r*r))
	{
		std::cout << "IN";
	}
	else {
		std::cout << "OUT";
	}
}
