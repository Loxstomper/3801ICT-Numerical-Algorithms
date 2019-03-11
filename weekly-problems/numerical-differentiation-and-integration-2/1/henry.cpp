#include <iostream>
#include <math.h>

double f(double x)
{
    return (2 * x + 3 / x) * (2 * x + 3 / x);
}

double multi_trap(int n, double a, double b)
{
    double step = (b - a) /  n;
    double result = f(a)+ f(b);

    for(int i = 1; i < n; i++)
    {
        result += 2 * f(a + i * step);
    }
    return result * step / 2;
}

double error(double previous, double current)
{
    return ((previous - current) / previous) * 100;
}


int main() {
    double I[10][10], a = 1, b = 2;
    int n = 1, max_iter = 10;

    bool stop = false;
    double previous = 99;
    double target = 0.5 * (pow(10, 0));

    I[0][0] = multi_trap(n, a, b);

    for(int i = 1; i < max_iter && !stop; i++)
    {
        n = pow(2,i);

        I[i][0] = multi_trap(n,a,b);

        for(int k = 1; k < i + 1 && !stop; k++)
        {
            I[i][k] = (pow(4,k) * I[i][k-1] - I[i - 1][k - 1]);
            I[i][k] /= (pow(4,k) - 1);

            if (error(previous, I[i][k]) < target)
            {
                std::cout << "FINISHED: " << I[i][k] << std::endl;
                stop = true;

                // print the table
                for (int a = 0; a < i + 1; a ++)
                {
                    for (int b = 0; b < a; b ++)
                    {
                        std::cout << I[a][b] << "\t";
                    }

                    std::cout << std::endl;
                }
            }

            previous = I[i][k];

        }
    }
    // for(int a = 0; a < 10; a++){
    //     for (int b = 0; b < a; b++){
    //         std::cout << I[a][b] << "\t";
    //     }
    //     std::cout << std::endl;
    // }

}