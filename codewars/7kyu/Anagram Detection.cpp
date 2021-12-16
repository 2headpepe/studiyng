#include <string>


bool isAnagram(std::string test, std::string original){
  for(int i =0;i<test.length();++i)
  {
      if(test[i]<'a')test[i]='a'+test[i]-'A';
  }
  for(int i =0;i<original.length();++i)
  {
      if(original[i]<'a')original[i]='a'+original[i]-'A';
  }
  std::sort(test.begin(),test.end());
  std::sort(original.begin(),original.end());
  std::cout<<test<<" "<<original;
  if(test==original) return 1;
  return 0;
}
