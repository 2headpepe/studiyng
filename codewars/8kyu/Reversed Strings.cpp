#include <string>
using namespace std ; 

string reverseString (string str )
{
  string new_str=str;
  for(int i=str.length()-1;i>=0;--i) new_str[i]=str[i];
  return new_str ;
}
