#include <iostream>
#include <math.h>

double f(double x)
{
    return (2 * x + 3 / x) * (2 * x + 3 / x);
}

double gauss(double a, double b)
{
    int n = 4;

    double ti[] = {-0.8611363116, -0.3399810436, 0.3399810436, 0.8611363116};
    double ci[] = { 0.3478548451, 0.6521451549, 0.6521451549, 0.3478548451};

    double r = 0;

    double m = (b - a) / 2.0;
    double c = (b + a) / 2.0;

    for (int i = 1; i <= n; i ++)
    {
        r += ci[i - 1] * f(m * ti[i - 1] + c);
    }

    r *= m;

    return r;
}


int main(int argc, char** argv) 
{
    std::cout << gauss(1, 2) << std::endl;

    exit(0);
}