#include<string>
bool XO(const std::string& str)
{
  int x=0,o=0;
  for(int i=0;i<str.length();++i)
  {
    if ((str[i]=='x')||(str[i]=='X')) x++;
    if ((str[i]=='o')||(str[i]=='O')) o++;
  }
  if(x==o) return true;
  return false;
}
