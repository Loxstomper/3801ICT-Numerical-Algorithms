// copied from wayne in class

#include <iostream>
#include <cmath>

double f(double x)
{
    return (2 * x + 3 / x) * ( 2 * x + 3 / x);
}

double multi_trap(int n, double a, double b)
{
    double step = (b - a) / n;
    double result = f(a) + f(b);

    for(int i = 1; i < n; i++)
    {
        result += 2 * f(a + i * step);
    }

    return result * step / 2;
}


int main(int argc, char** argv)
{
    double I[10][10], a = 1, b = 1;
    int n = 1, max_iter = 10;

    I[0][0] = multi_trap(n, a, b);

    for (int i = 1; i < max_iter; i ++)
    {
        n = pow(2, i);
        I[i][0] = multi_trap(n, a, b);

        for (int k = 1; k <  i + 1; k ++)
        { 
            I[i][k] = (pow(4, k) * I[i][k - 1] - I[i - 1][k - 1]);
            I[i][k] /= (pow(4, k) - 1);
        }
    }

    // std::cout << I[9][9] << std::endl;

    for (int i = 0; i < 9; i ++)
    {
        for (int j = 0; j < i; j ++)
        {
            std::cout << I[i][j] << " ";
        }

        std::cout << std::endl;
    }

    exit(0);
}