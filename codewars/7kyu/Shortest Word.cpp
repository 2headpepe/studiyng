#include <string>
int find_short(std::string str)
{
  int x=0,res=str.length();
  for(int i =0;i<str.length();++i)
  {
      if((x==0)||(str[i]!=' ')) 
      {
        x++;
      }
      else
      {
        if(x<res) res=x;
        x=0;
      }
  }
  if(x<res) res=x;
  return res;
}
