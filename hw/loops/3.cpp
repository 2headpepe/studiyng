//Для заданных значений n и x вычислить выражение: S = sin(x) + sin(sin(x)) + ... + sin(sin( ... (sin (x)) ... ))
#include <iostream>


int main() {
    int n;
    float x;
    std::cin>>n>>x;
    float S=0.,curr=sin(x);
    for(int i=1;i<n;++i){
        S+=curr;
        curr=sin(curr);
    }
    std::cout<<S;
}
