#include <stdio.h>
#include <math.h>

void calc(double a, double b, double c, double xs[])
{
    xs[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
    xs[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
}

int main(int argc, char** argv)
{
    double a, b, c;

    a = 1; b = 3000.001; c = 3;

    double x[] = {0, 0};

    calc(a, b, c, x);

    printf("%f %f \n", x[0], x[1]);

    return 0;
}