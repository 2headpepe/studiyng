#include <string>

std::string createPhoneNumber(const int arr [10]){
  std::string res="(";
  res+=std::to_string(arr[0]);
  res+=std::to_string(arr[1]);
  res+=std::to_string(arr[2]);
  res+=") ";
  res+=std::to_string(arr[3]);
  res+=std::to_string(arr[4]);
  res+=std::to_string(arr[5]);
  res+="-";
  res+=std::to_string(arr[6]);
  res+=std::to_string(arr[7]);
  res+=std::to_string(arr[8]);
  res+=std::to_string(arr[9]);
  return res;
}
