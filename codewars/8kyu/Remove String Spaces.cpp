#include <string>
std::string no_space(std::string x)
{
    std::string new_s="";
    for(int i=0;i<x.length();++i)
    {
      if (x[i]!=' ') new_s+=x[i];
    }
    return new_s;
}
