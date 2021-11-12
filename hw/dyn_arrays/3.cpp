#include<iostream>
void snakeArray(int** A, int n)
{
	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[n];
	}
	for (int j = 0; j < n; j+=2)
	{
		for (int i = 0; i < n; ++i)
		{
			A[i][j] = n * j + i;
		}
	}
	for (int j = 1; j < n; j += 2)
	{
		for (int i = 0; i < n; ++i)
		{
			A[i][j] = n * j +n - i-1;
		}
	}
	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int main()
{
	int n;
	std::cin >> n;
	int** mas = new int*[n];
	snakeArray(mas, n);
}
