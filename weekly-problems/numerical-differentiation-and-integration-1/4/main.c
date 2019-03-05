#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x)
{
    return 0.2 + 25 * x - 200 * pow(x, 2) + 675 * pow(x, 3) - 900 * pow(x, 4) + 400 * pow(x, 5);
}

double trap(double a, double b)
{
    return (b - a) * (f(a) + f(b)) / 2;
}

double trueError(double real, double approx)
{
    return ((real - approx) / real) * 100;
}

int main(int argc, char** argv)
{
    double approx = trap(0, 0.8);
    double real   = 1.64053;
    printf("%.20f \n", trap(0, 0.8));
    printf("%.20f%% \n", trueError(real, approx));
    return 0;
}