static long findMissing(std::vector<long> list){
  int d=list[1]-list[0];
  if (list.size()==2) return list[0]+d/2;
  if((list[2]-list[1])==d/2) return list[0]+d/2;
  if((list[2]-list[1])==2*d) return list[1]+d;
  for(int i=3;i<list.size();++i)
  {
    if((list[i]-list[i-1])!=d) return list[i-1]+d;
  }
}
