#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n) 
{
    if (n < 1) 
    {
        return 1;
    }

    return n * factorial(n - 1);
}

double calc(double n, double Es) 
{
    double result = 1;
    double error = 999;
    double previous = 0;
    int neg = 1;

    for (int i = 2; error > Es ; i += 2) 
    {
        if (!neg) 
        {
            result += (pow(n, i) / factorial(i));
            neg = 1;
        }
        else 
        {
            result -= (pow(n, i) / factorial(i));
            neg = 0;
        }

        error = fabs((result - previous) / result) * 100;
        previous = result;

        printf("%.20f %f\n", result, error);
    }

    return result;
}


int main(int argc, char** argv)
{
    int n_sig_figures = 8;

    double Es = (0.5 * pow(10, (2 - n_sig_figures))) * 100;
    double n = 0.3 * M_PI;

    calc(n, Es);

    // printf("%f \n", calc(n, Es));

    return 0;
}