//Написать программу, которая вычисляет число pi с заданной пользователем точностью. Под точностью понимается абсолютная величина очередного слагаемого. Для вычисления значения числа pi воспользоваться формулой: pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...) Определить какое количество дробей необходимо было добавить к сумме, чтобы обеспечить заданную точность. Запомнить кол-во, например в переменной N.
#include<iostream>
int main(){
  float eps,res=0;
  std::cin>>eps;
  float i=1,x=1;
  do 
  {
    res+=x/(2*i-1);
    x=(-1)*x;
    ++i;
  }while(1/(2*i-1)>eps);
  std::cout<<res*4<<" "<<i-1;
}
