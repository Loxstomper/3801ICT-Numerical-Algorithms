#include <iostream>
#include <cmath>


// use float16

// f'(x) = -0.4x^3 - 0.45x^2 -x - 0.15
// f'(0.5) = -0.8125

double f(double x)
{
    return -0.1 * pow(x, 4) - 0.15 * pow(x, 3) - 0.5 * pow(x, 2) - 0.15 * x + 1.2;
}

double centeredDifference(double x, double h, double(*f)(double))
{
    double forward, backward;

    forward = f(x + h);
    backward = f(x - h);

    // need to have the truncation error too;
    return (forward - backward) / (2 * h);
}

double error(double actual, double approx)
{
    return ((actual - approx) / actual) * 100;
}

int main(int argc, char** argv)
{
    double actual = -0.8125;
    double x = 0.5;
    double h = 1;

    double approx;

    for (int i = 0; i < 1000; i ++) 
    {
        approx = centeredDifference(x, 1.0 / i, &f);
        std::cout << approx << "\t" << error(actual, approx) << "%%" << std::endl;
    }

    
    exit(0);
}