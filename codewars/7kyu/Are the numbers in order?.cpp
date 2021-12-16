bool isAscOrder(std::vector<int> arr)
{
  for (int i=1;i<arr.size();++i)
  {
    if(arr[i-1]>arr[i]) return false;  
  }
  return true;
}
