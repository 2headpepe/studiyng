//Дан массив A размера N. Вывести его элементы в следующем порядке: A[1], A[N], A[2], A[N-1], A[3], A[N-2], ...

#include <iostream>

int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    int* array = new int[n];
    std::cout << "enter elements of array: ";
    for (int i = 0; i < n; ++i)
        std::cin >> array[i];
    std::cout << "collapsing array: ";
    bool check = n == (n / 2) * 2 ? true : false;
    if(n%2==0)
      for (int i = 0; i < n / 2; ++i)
        std::cout<<array[i]<<" "<<array[n-i-1]<<" ";
  
    if(n%2==1)
      for (int i = 0; i <= (n-1) / 2; ++i)
      {
        if(i*2==n-1) std::cout<<array[i];
        else std::cout<<array[i]<<" "<<array[n-i-1]<<" ";
      }
    delete[] array;
}
