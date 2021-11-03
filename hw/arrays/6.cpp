//Задача 6. Дан целочисленный массив размера N, не содержащий одинаковых чисел.Проверить, образуют ли его элементы арифметическую прогрессию.Если образуют, то вывести разность прогрессии, если нет -- вывести 0.
#include<iostream>
int main() {
	int N;
	std::cin >> N;
	int* mas = new int[N];
	for (int i = 0; i < N; ++i)
	{
		std::cout << i << ": ";
		std::cin >> mas[i];
	}
	bool flag = 0;
	int curr = mas[1],d=mas[1]-mas[0];
	if(N>2)
		for (int i = 2; i < N; ++i)
		{
			if ((mas[i] - curr) == d)
			{
				curr = mas[i];
			}
			else
			{
				flag = 1;
				
			}
	}
	if (!flag) std::cout << "YESSSSSSSSSSSSSS SIR";
	if(flag)std::cout << "NO WAY, BRO";
}
