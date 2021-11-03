#include<iostream>
int main(){
  float x,y;
  std::cin>>x>>y;
  bool b=false;
  if (((x+1)*(x+1)+y*y<1)&&(y<=0)) b=true;
  if (((x-1)*(x-1)+y*y<1)&&(y<=0)) b=true;
  if ((y<=x/2+2)&&(x<=0)&&(x>=-1)&&(y>=0)) b=true;
  if ((y<=x/2+2)&&(x<=0)&&(x>=-1)&&(y>=0)) b=true;
  if ((y<=-2*x+2)&&(x<=1)&&(x>=0)&&(y>=0)) b=true;
  
  if(b) std::cout<<"in";  
  if(!b) std::cout<<"out";
}
