#include <iostream>
#include <cmath>

int main() {
    double eps, dx, x1, x2;

    std::cin >> eps;
    std::cin >> dx;
    std::cin >> x1;
    std::cin >> x2;
    while (x1 <= x2)
    {
        double sum = 0;
        double curr = x1;
        int a = 1;
        while (std::abs(curr) > eps)
        {
            sum += curr;
            a += 2;
            curr = -curr * x1 * x1 / (a * (a - 1));
        }
        std::cout << "x = " << x1 << ", f(x) = " << sum << ", sin = " << sin(x1) << "\n";
        x1 += dx;
    }
    return 0;
}
