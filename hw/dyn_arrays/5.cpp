#include <iostream>
#include <iomanip>



int main()
{
    int n1, n2, p = 1, u, g = 0;
    

    std::cin >> n2 >> n1;
    int** mas = new int*[n1];
    for (int i = 0; i < n1; ++i) mas[i] = new int[n2];
    
    int i = 0, j = 0;

    for (int t = 1; t <= std::min(n1, n2); t += 2)
    {
        u = i;
        for (; j < n2 - t + u; j++)
        {
            mas[i][j] = p;
            p++;
        }

        for (; i < n1 - t + u; i++)
        {
            mas[i][j] = p;
            p++;
        }

        if (std::min(n1, n2) != 1)
        {
            for (; j > 0 + u; j--)
            {
                mas[i][j] = p;
                p++;
                if (p == n1 * n2 + 1)
                {
                    g = 1;
                    break;
                }
            }
            if (g == 1) break;

            for (; i > 0 + u; i--)
            {
                mas[i][j] = p;
                p++;
                if (p == n1 * n2 + 1)
                {
                    g = 1;
                    break;
                }
            }
            if (g == 1) break;
        }
        else
        {
            mas[n1 - 1][n2 - 1] = std::max(n1, n2);
        }
        i++;
        j++;
    }
    if (n1 % 2 != 0 && n1 % 2 != 0 && n1 == n2)
    {
        mas[n1 / 2][n2 / 2] = n1 * n2;
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
