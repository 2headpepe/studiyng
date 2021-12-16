int countSmileys(std::vector<std::string> arr)
{
  int res=0;
  for(int i=0;i<size(arr);++i)
  {
    std::string s=arr[i];
    if((s[0]==':')||(s[0]==';'))
    {
      if((s[1]==')')||(s[1]=='D')) res++;
      else if ((s[1]=='-')||(s[1]=='~'))
      {
        if((s[2]==')')||(s[2]=='D')) res++;
      }
    }
  }
  return res;
}
