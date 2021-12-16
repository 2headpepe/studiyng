std::vector<int> tribonacci(std::vector<int> signature, int n)
{
  std::vector<int> result(n);
  if(n>=1)
  {
    result[0]=signature[0];
    if(n>=2)
    {
      result[1]=signature[1];
      if(n>=3)
      {
        result[2]=signature[2];
      }
    }
  }
  if(n<=3) return result;
  for(int i=3;i<n;++i)
  {
    result[i]=result[i-1]+result[i-2]+result[i-3];
  }
  return result;
  
}
