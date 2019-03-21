#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <limits>


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

    forward  = f(x + h);
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
    float h;

    float approx;

    // h = 10.0;
    h = 0.0055428994652341424;

    // for (int i = 1; i < 100; i ++) 
    // {
    //     // h = 1.0 / i;
    //     approx = centeredDifference(x, h, &f);
    //     // std::cout << approx << "\t" << error(actual, approx) << "%%" << std::endl;
    //     // std::cout << i << "\t" << error(actual, approx) << std::endl;
    //     // printf("%.20f\t%.20f\n", approx, error(actual, approx));
    //     printf("%.20f\t%.20f\n", h, error(actual, approx));
    //     h /= 2;
    //     // h *= (3/4);
    // }

    std::cout << std::numeric_limits<float>::epsilon() << std::endl;

    std::cout << centeredDifference(x, h, &f);

    // std::cout << std::fixed << std::setprecision(20) << std:: 

    
    exit(0);
}
