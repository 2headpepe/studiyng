#include<iostream>

int main()
{
  int n;
  std::cin>>n;
  int* mas = new int[n];
  int sum=0;
  for(int i =0;i<n;++i)
  {
    std::cin>>mas[i];
    sum+=mas[i];
  }
  std::cout<<n*(n+1)/2-sum;
}
