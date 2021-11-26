#include <vector>

PeakData pick_peaks(const std::vector<int> &v) {
  PeakData result;
  std::vector<int> x,peak;
  for(int i=1;i<v.size()-1;++i)
  {
    if((v[i]>v[i-1])&&(v[i]>v[i+1]))
    {
      x.push_back(i);
      peak.push_back(v[i]);
    }
    if((v[i]>v[i-1])&&(v[i]==v[i+1]))
    {
      int j=i+1;
      while(v[j]==v[i]) ++j;
      if(v[j]<v[i]) 
      {
        x.push_back(i);
        peak.push_back(v[i]);
      }
    }
  }
  result.pos=x;
  result.peaks=peak;
  return result;
}
