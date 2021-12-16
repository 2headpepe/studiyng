#include <string>
using namespace std;

string rot13(string msg)
{
  for(int i =0;i<msg.length();++i)
  {
    if((msg[i]>='A')&&(msg[i]<='Z'))
    {
      if(msg[i]+13>'Z') msg[i]-=13;
      else msg[i]+=13;
    }
    else if ((msg[i]>='a')&&(msg[i]<='z'))
    {
      if(msg[i]+13>'z') msg[i]-=13;
      else msg[i]+=13;
    }
  }
  return msg;
}
