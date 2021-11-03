//Для заданного значения n вычислить выражение: S = 1 + 1/2 + 1/3 + ... + 1/n
#include <iostream>

int main() {
    int n;
    std::cin>>n;
    float S=0;
    for(int i=1;i<=n;++i){
        S+=1./i;
    }
    std::cout<<S;
}
