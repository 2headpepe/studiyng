#include <iostream>

int main() {
    int n;
    std::cout << "Enter n:";
    std::cin >> n;
    int i =1,c=1;
    while((n-i)>0)
    {
        
        for(int j=1;j<=i;++j)
        {

            if((n-i)>0)
            {
                ++c;
                n-=i;
            }
        }
        ++i;
    }
    std::cout<<c;
}
