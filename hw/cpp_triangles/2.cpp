#include <iostream>

int main()
{
    int space, rows;
    std::cout << "Enter number of rows\n";
    std::cin >> rows;
    for (int i = 1; i <= rows; ++i)
    {
        for (space = 1; space <= rows - i; ++space)
        {
            std::cout << " ";
        }
        int j = 0;
        while (j != 2 * i - 1)
        {
            std::cout << "*";
            ++j;

        } std::cout << std::endl;

    }
    return 0;

}
