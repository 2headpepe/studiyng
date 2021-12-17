//Перевести заданное пользователем число (целое, положительнео) в заданную пользователем систему счисления (от 2 до 16). Для систем счисления более 10 использовать буквы английского алфавита ABCDEF
#include<iostream>
int main(){
  int x,N;
  std::cin>>x>>N;
  int res=0,i=1;
  if(N>10){
    while(x){
      i=1;
      int newx=x;
      while(newx>=N){
        newx/=N;
        i*=N;  
      }
      x-=i*newx;
      switch(newx){
        case 10: std::cout<<"A";break;
        case 11: std::cout<<"B";break;
        case 12: std::cout<<"C";break;
        case 13: std::cout<<"D";break;
        case 14: std::cout<<"E";break;
        case 15: std::cout<<"F";break;
        default:std::cout<<newx;break;
      }
    }
  }
  else if (N==10) std::cout<<x;
  else
  {
    while(x){
      res+=i*(x%N);
      i*=10;
      x/=N;
    }
    std::cout<<res;
  }
}
