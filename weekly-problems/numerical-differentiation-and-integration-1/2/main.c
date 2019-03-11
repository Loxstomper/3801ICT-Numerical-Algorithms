#include <stdio.h>
#include <math.h>

double f(double x)
{
    return -0.1 * pow(x, 4) - 0.15 * pow(x, 3) - 0.5 * pow(x, 2) - 0.25 * x + 1.2;
}

double forward(double x, double h) 
{
    return (f(x + h) - f(x)) / h;
}

double backward(double x, double h) 
{
    return (f(x) - f(x - h)) / h;
}

double central(double x, double h) 
{
    return (f(x + h) - f(x - h)) / (2 * h);
}

double trueError(double exact, double approx)
{
    return fabs((exact - approx) / exact) * 100;
}

int main(int argc, char** argv)
{
    // f(x) = 0.1x^4 - 0.15x^3 - 0.5x^2 - 0.25x + 1.2
    // at x = 0.5 and h = 0.25

    // analytical
    // 0.4x^3 - 0.45x^2 - 1x - 0.25
    // -0.8125

    double exact = -0.8125;

    printf("\n");
    printf("forward  h=0.5  %.20f True Error: %.20f%%\n", forward(0.5, 0.5),  trueError(exact, forward(0.5, 0.5)));
    printf("backward h=0.5  %.20f True Error: %.20f%%\n", backward(0.5, 0.5), trueError(exact, backward(0.5, 0.5)));
    printf("centered h=0.5  %.20f True Error: %.20f%%\n", central(0.5, 0.5),  trueError(exact, central(0.5, 0.5)));
    printf("\n");
    printf("forward  h=0.25 %.20f True Error: %.20f%%\n", forward(0.5, 0.25), trueError(exact, forward(0.5, 0.25)));
    printf("backward h=0.25 %.20f True Error: %.20f%%\n", backward(0.5, 0.25),trueError(exact, backward(0.5, 0.25)));
    printf("centered h=0.25 %.20f True Error: %.20f%%\n", central(0.5, 0.25), trueError(exact, central(0.5, 0.25)));
    printf("\n");


    return 0;
}
