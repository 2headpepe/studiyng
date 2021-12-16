std::string reverse_words(std::string str)
{
  std::string x="",res="",x1="";
  for(int i =0;i<str.length();++i)
  {
    if((str[i]!=' ')) x+=str[i];
    else
    {
      x1=x;
      for(int j=0;j<x.length();++j) x1[j]=x[x.length()-j-1];
      res+=x1;
      res+=" ";
      x="";
      x1="";
    }
    if(i==str.length()-1)
    {
      x1=x;
      for(int j=0;j<x.length();++j) x1[j]=x[x.length()-j-1];
      res+=x1;
      x="";
      x1="";
    }
  }
  
  return res;
}
