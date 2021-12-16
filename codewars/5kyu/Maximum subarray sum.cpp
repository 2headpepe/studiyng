#include <vector>

int maxSequence(const std::vector<int>& arr){
  int res=0,max_n=0,c=0;
  if(arr.size()>=1)
    for(unsigned int i =0;i<arr.size();++i)
    {
      c+=arr[i];
      if(c<0) c=0;
      if(c>max_n) max_n=c;
    }
  return max_n;
}
