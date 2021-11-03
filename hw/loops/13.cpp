//Перевести заданное целое число (<4000) в систему римского счета.
#include<iostream>
int main(){
  int n;
  std::cin>>n;
  while(n>=1000)
  {
    n-=1000;
    std::cout<<"M";
  }
  if((n>900) &&(n<1000)){
    n-=900;
    std::cout<<"CM";
  }
  while(n>=500)
  {
    n-=500;
    std::cout<<"D";
  }
  if((n>400) &&(n<500)){
    n-=400;
    std::cout<<"CD";
  }
  while(n>=100){
    n-=100;
    std::cout<<"C";
  }
  if((n>90) &&(n<100)){
    n-=90;
    std::cout<<"XC";
  }
  while(n>=50)
  {
    n-=50;
    std::cout<<"L";
  }
  if((n>40) &&(n<50)){
    n-=40;
    std::cout<<"XL";
  }
  while(n>=10)
  {
    n-=10;
    std::cout<<"X";
  }
  if(n==9) 
  {
    n-=9;
    std::cout<<"|X";
  }
  while(n>=5){
    n-=5;
    std::cout<<"V";
  }
  if(n==4)
  {
    n-=4;
    std::cout<<"|V";
  }
  while(n>=1){
    --n;
    std::cout<<"|";
  }
}
