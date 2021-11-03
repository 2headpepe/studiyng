//Задача 1. Вывести в консоль строку с одной звездочкой, строку с двумя звездочками, с тремя и т.д. Количество строк спрашивать у пользователя (не более 25 строк).
#include <iostream>

int main()
{
    int n = 0;
    std::cout << "Input height\n";
    std::cin >> n;
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
