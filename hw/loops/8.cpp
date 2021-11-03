//Вычислить сумму и произведение цифр целого числа, введенного пользователем.
#include<iostream>
int main(){
  int x;
  std::cin>>x;
  int sum=0,res=1;
  while(x)
  {
    sum+=x%10;
    res*=x%10;
    x/=10;
  }
  std::cout<<sum<<res;
}
