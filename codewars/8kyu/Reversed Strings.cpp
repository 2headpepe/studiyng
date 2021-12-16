#include <string>
using namespace std ; 

string reverseString (string str )
{
  string new_str="";
  for(int i=str.length()-1;i>=0;--i) new_str+=str[i];
  return new_str ;
}
