#include <string>
using namespace std ; 

string reverseString (string str )
{
  char x=' ';
  for(int i=0;i<str.length()/2;++i)
  {
    x=str[i];
    str[i]=str[str.length()-1-i];
    str[str.length()-1-i]=x;

  } 
  return str;
}
