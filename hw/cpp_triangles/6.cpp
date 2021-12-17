#include <iostream>

int main(){
    int h;
    std::cout << "Enter h/2: ";
    std::cin >> h;
    for (int i = 0; i < h; i++)
    {
        int stars = 2 * i + 1;
        for (int j = 0; j < 2 * h + 1; j++)
        {
            if (j == h - i || j == h + i)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    for (int i = h; i >= 0; i--)
    {
        int stars = 2 * i + 1;
        for (int j = 0; j < 2 * h + 1; j++)
        {
            if (j == h - i || j == h + i)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}
