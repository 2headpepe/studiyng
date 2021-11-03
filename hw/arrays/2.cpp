//Схема Горнера.Коэффициенты многочлена находятся в массиве A размерности(N + 1), где N -- степень многочлена.Вычислить значение этого многочлена в точке x, то есть A[N]x^ N + ... + A[1]x + A[0], используя схему Горнера.
#include <iostream>
int main() {
	int N;
	float x;
	std::cin >> N >> x;
	int* m = new int[N+1];
	int sum = 0;
	float curr = 1;
	for (int i = 0; i <= N; ++i)
	{
		std::cout << i << ": ";
		std::cin >> m[i];
		sum += m[i] * curr;
		curr *= x;
		std::cout<< "    : " << sum<<std::endl;
	}
	
	delete [] m;
}
