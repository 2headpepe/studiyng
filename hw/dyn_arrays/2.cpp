#include<iostream>
int length_x(int x)
{
	int res = 0;
	while (x)
	{
		res++;
		x /= 10;
	}
	return res;
}
int main()
{
	int n, m,max=0;
	std::cin >> n >> m;
	int** mas = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		mas[i] = new int[m];
	}
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			mas[i][j] = rand();
			if (mas[i][j] > max) max = mas[i][j];
		}
	}
	max = length_x(max);
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			int x = length_x(mas[i][j]);
			
			std::cout << mas[i][j];
			for (int i = 0; i <= max - x; ++i) std::cout << " ";
		}
		std::cout << std::endl;
	}
}
