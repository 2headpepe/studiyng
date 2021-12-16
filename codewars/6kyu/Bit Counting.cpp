unsigned int countBits(unsigned long long n){
  unsigned int x=0;
  while (n)
  {
    if(n%2==1) x++;
    n/=2;
  }
  return x;
}
