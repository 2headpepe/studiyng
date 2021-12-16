#include<cmath>
bool narcissistic( int value ){
  int digits=std::to_string(value).length();
  int sum=0,new_x=value;
  for(int i=0;i<digits;++i)
  {
    sum+=pow(value%10,digits);
    value/=10;
  }
  if(sum==new_x) return true;
  return false;
}
