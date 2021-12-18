#include <iostream>
#include <iomanip>

int main()
{
    int n1, n2, j, i, k = 1, l;
    
    std::cin >> n1 >> n2;
    int** mas = new int* [n1];
    for (int i = 0; i < n1; ++i) mas[i] = new int [n2];
    
    for (l = 0; l < n1 + n2 - 1; l++)
    {
        if(l%2==1)
            for (i = 0; i < n1; i++)
            {

                for (j = 0; j < n2; j++)
                {
                    if (i + j == l)
                    {
                        mas[i][j] = k;
                        k++;
                    }
                }
            }
        else
            for (j = 0; j < n1; j++)
            {

                for (i = 0; i < n2; i++)
                {
                    if (i + j == l)
                    {
                        mas[i][j] = k;
                        k++;
                    }
                }
            }
    }


    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            std::cout.width(4);
            std::cout << mas[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}
