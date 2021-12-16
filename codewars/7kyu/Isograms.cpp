#include<string>
std::string tolower_str(std::string str) {
  for (size_t i = 0; i < str.size(); ++i)
    if (str[i] >= 'A' and str[i] <= 'Z')
      str[i] = static_cast<char>(str[i] + 32);
  return str;
}
int count_c(std::string str,char c)
{
  int res=0;
  for(int i=0;i<str.length();++i)
  {
    if(str[i]==c) res++;
  }
  return res;
}
bool is_isogram(std::string str) {
  str=tolower_str(str);
  for(int i=0;i<str.length();++i)
  {
    if(count_c(str,str[i])>1) return false;
  }
  return true;
}
