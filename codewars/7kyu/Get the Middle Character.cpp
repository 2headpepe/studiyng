#include<string>
std::string get_middle(std::string input) 
{
  int l=input.length();
  if(l%2==0)
  {
    std::string x="";
    x+=input[l/2-1];
    x+=input[l/2];
    return x;
  }
  std::string x="";
  x+=input[l/2];  
  return x;
}
