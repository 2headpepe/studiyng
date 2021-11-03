//Задача 3. Вывести ромб из зведочек. Высоту половины ромба задает пользователь.
#include <iostream>

int main()
{
    std::cout << "Enter Height/2\n ";
    int num;
    std::cin >> num;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < num - i; j++) std::cout << " ";
        for (int k = 0; k < i * 2 - 1; k++) std::cout << "*";
        std::cout << std::endl;
    }

    for (int i=num-2; i >= 0; i--)
    {
        for (int j = 0; j < num - i; j++) std::cout << " ";
        for (int k = 0; k < i * 2 - 1; k++) std::cout << "*";
        std::cout << std::endl;
    }
    return 0;
}
