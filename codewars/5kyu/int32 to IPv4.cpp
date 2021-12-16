#include<cmath>
std::string uint32_to_ip(uint32_t ip)
{
  long long int x=ip;
  
  std::string result=std::to_string(x/(int)pow(2.,24));
  result+=".";
  x=x%(int)pow(2.,24);
  
  result+=std::to_string(x/(int)pow(2.,16));
  result+=".";
  x%=(int)pow(2.,16);
  
  result+=std::to_string(x/(int)pow(2.,8));
  result+=".";
  x%=(int)pow(2.,8);
  
  result+=std::to_string(x);
  
  return result;
}
