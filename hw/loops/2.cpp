//Для заданного значения n вычислить выражение: S = 1 + 1/2 + 1/4 + ... + 1/2^n
#include <iostream>

int main() {
    int n;
    std::cin>>n;
    float S=0.,curr=1.;
    for(int i=1;i<=n;++i){
        S+=curr;
        curr/=2.;
    }
    std::cout<<S;
}
