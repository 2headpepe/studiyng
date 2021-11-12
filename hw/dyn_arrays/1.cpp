  #include<iostream>

int main()
{
	int n,m;
	std::cin >> n >> m;
	int **mas = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		mas[i] = new int[m];
	}

	for (int j = 0; j < m; j+=2)
	{
		for (int i = 0; i < n; ++i)
		{
			mas[i][j] = n * j + i;
		}
	}
	for (int j = 1; j < m; j += 2)
	{
		for (int i = n - 1; i >= 0; --i)
		{
			mas[i][j] = n * j + n-i-1;
		}
	}
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << mas[i][j] << " ";
		}
		std::cout << std::endl;
	}



	for (int i = 0; i < n; ++i)
	{
		delete[] mas[i];
	}
}
