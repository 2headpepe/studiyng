#include <string>
std::string tolower_str(std::string str) {
  for (size_t i = 0; i < str.size(); ++i)
    if (str[i] >= 'A' and str[i] <= 'Z')
      str[i] = static_cast<char>(str[i] + 32);
  return str;
}
int count_ch(std::string str,char x)
{
  int res=0;
  
  for(int i=0;i<str.length();++i)
  {
    if(str[i]==x) ++res; 
  }
  return res;
}
std::string duplicate_encoder(const std::string& word){
  std::string word_new=tolower_str(word);
  std::string s="";
  for (int i=0;i<word.length();++i)
  {
    int x=count_ch(word_new,word_new[i]);
    if(x>1) s+=")";
    if(x<=1) s+="(";
  }
  return s;
}
