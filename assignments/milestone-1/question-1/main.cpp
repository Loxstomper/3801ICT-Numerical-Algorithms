#include <iostream>
#include <cstdio>
#include <cmath>


// use float16

// f'(x) = -0.4x^3 - 0.45x^2 -x - 0.15
// f'(0.5) = -0.8125

float f(float x)
{
    return -0.1 * pow(x, 4) - 0.15 * pow(x, 3) - 0.5 * pow(x, 2) - 0.15 * x + 1.2;
}

float centeredDifference(float x, float h, float(*f)(float))
{
    float forward, backward;

    forward = f(x + h);
    backward = f(x - h);

    // need to have the truncation error too;
    return (forward - backward) / (2 * h);
}

float error(float actual, float approx)
{
    return fabs((actual - approx) / actual) * 100;
}

int main(int argc, char** argv)
{
    float actual = -0.8125;
    float x = 0.5;
    float h = 1;

    float approx;

    for (int i = 1; i < 1000; i ++) 
    {
        approx = centeredDifference(x, 1.0 / i, &f);
        // std::cout << approx << "\t" << error(actual, approx) << "%%" << std::endl;
        // std::cout << i << "\t" << error(actual, approx) << std::endl;
        printf("%.20f\t%.20f\n", approx, error(actual, approx));
    }

    
    exit(0);
}