#include<cmath>
bool is_square(int n)
{
  int x=(int)sqrt(n);
  
  if (x*x==n) return true;
  return false;
}
