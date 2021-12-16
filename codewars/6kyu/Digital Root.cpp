int digital_root(int n)
{
  int sum=0,res=n;
  while(res>9)
  {
    while(res)
    {
      sum+=res%10;
      res/=10;
    }
    res=sum;
    sum=0;
  }
  return res;
}
