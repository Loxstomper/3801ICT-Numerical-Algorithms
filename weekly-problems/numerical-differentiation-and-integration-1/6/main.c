#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 0.2 + 25 * x - 200 * pow(x, 2) + 675 * pow(x, 3) - 900 * pow(x, 4) + 400 * pow(x, 5);
}

double trueError(double real, double approx)
{
    return (fabs((real - approx) / real)) * 100;
}

double simp(double a, double b, int n)
{
    double h = (b - a) / n;
    double x = a;
    
    double sum = f(x);

    for(int i = 1; i < n - 2; i += 2)
    {
        x = x + h;
        sum += 4 * f(x);
        x = x + h;
        sum += 2 * f(x);
    }

    x = x + h;
    sum += 4 * f(x);
    sum += f(b);

    return (b - a) * sum / (3 * n);
}

int main(int argc, char** argv)
{
    double approx;
    double real = 1.64053;

    for (int i = 2; i < 10; i += 2)
    {
        approx = simp(0, 0.8, i);

        printf("steps: %d value: %.20f error: %.20f%% \n", i, approx, trueError(real, approx));
    }


    
    return 0;
}