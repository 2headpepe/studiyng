//Перевести заданное пользователем число (целое, положительнео) в 16-ю систему счисления и вывести на экран.
#include<iostream>
int main(){
  int x;
  std::cin>>x;
  int res=0,i;
  while(x){
    i=1;
    int newx=x;
    while(newx>=16){
      newx/=16;
      i*=16;  
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
