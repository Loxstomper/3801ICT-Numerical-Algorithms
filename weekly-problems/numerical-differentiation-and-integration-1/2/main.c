#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 0.1 * pow(x, 4) - 0.15 * pow(x, 3) - 0.5 * pow(x, 2) - 0.25 * x + 1.2;
}

double forward(double x, double h) 
{
    return (f(x + h) - f(x)) / h;
}

double backward(double x, double h) 
{
    return (f(x - h) - f(x)) / h;
}

double central(double x, double h) 
{
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main(int argc, char** argv)
{
    // f(x) = 0.1x^4 - 0.15x^3 - 0.5x^2 - 0.25x + 1.2
    // at x = 0.5 and h = 0.25

    printf("%.20f \n", forward(0.5, 0.25));
    printf("%.20f \n", backward(0.5, 0.25));
    printf("%.20f \n", central(0.5, 0.25));


    return 0;
}