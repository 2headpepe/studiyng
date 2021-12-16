class HiddenSeq
{
  public:
  static unsigned long long fcn(int n){
    unsigned long long int n1 = 1;
    unsigned long long int n2 = 2;
    unsigned long long int temp = 6 * n1 * n2 / (5 * n1 - n2);
    for (int i = 2; i <= n; ++i) {
      temp = 6 * n1 / (5 * n1 - n2) * n2;
      n1 = n2;
      n2 = temp;
    }
    return temp;
  };
};
