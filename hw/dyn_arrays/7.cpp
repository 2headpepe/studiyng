#include<iostream>
void shiftArray(int A[], int n, int k)
{
	int* m = new int[k];
	for (int i = 0; i < n - k; ++i)
	{
		m[i] = A[i];
		A[i] = A[i + k];
	}
	for (int i = n - k; i < n; ++i) A[i] = m[i - k - 1];
	std::cout << "Finish: ";
	for (int i = 0; i < n; ++i) std::cout << A[i]<<" ";
}
int main()
{
	int n, k;
	std::cin >> n >> k;
	int* mas = new int [n];
	std::cout << "Start: ";
	for (int i = 0; i < n; ++i)
	{
		mas[i] = rand();
		std::cout << mas[i] << ", ";
	}
	std::cout << "k = " << k << std::endl;
	shiftArray(mas, n, k);
	
}
	
