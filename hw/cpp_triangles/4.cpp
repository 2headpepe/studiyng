//Задача 4. Вывести несколько ромбов из звездочек. Высоту половины ромба и количество ромбов задает пользователь.
#include <iostream>


int main()
{
    std::cout << "Enter Height/2\n";
    int num;
    std::cin >> num;
    std::cout << "Enter quantity\n";
    int quan;
    std::cin >> quan;

    for (int i = 1; i <= num; ++i)
    {
        for (int counter = 0; counter < quan + 1; ++counter)
        {
            for (int j = 0; j < num - i; j++) std::cout << " ";
            for (int k = 0; k < i * 2 - 1; k++) std::cout << "*";
            for (int j = 0; j < num - i; j++) std::cout << " ";
        }
        std::cout << std::endl;

    }

    for (int i=num-1; i >= 0; --i)
    {
        for (int counter = 0; counter < quan + 1; ++counter)
        {
            for (int j = 0; j < num - i; ++j) std::cout << " ";
            for (int k = 0; k < i * 2 - 1; ++k) std::cout << "*";
            for (int j = 0; j < num - i; ++j) std::cout << " ";
        }
        std::cout << std::endl;

    }
    return 0;
}
