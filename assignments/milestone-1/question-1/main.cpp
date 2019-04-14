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
    // return fabs((double)(actual - approx) / actual) * 100;
}

float truncationError(float h) 
{
    // third deriv with epsilon
    //f'''(x) = -2.4x - 0.9
    return ((-2.4 * std::numeric_limits<float>::epsilon() - 0.9) / 6) * (h * h);
}

float hOpt()
{
    float e = std::numeric_limits<float>::epsilon();

    return cbrt((3 * e) / 2.1);
}

int main(int argc, char** argv)
{
    float actual = -0.8125;
    float x = 0.5;
    float h;

    float approx;

    h = 1.0;
    float bestH;
    float bestError = 100;
    float errorV;
    // h = 0.0055428994652341424;


    // printf("%.20f\t%.20f\n", centeredDifference(x, h, &f), error(centeredDifference(x, h, &f), actual));
    // return 0;

    for (int i = 1; i < 2000; i ++) 
    {
        // h = 1.0 / i;
        approx = centeredDifference(x, h, &f);
        // std::cout << approx << "\t" << error(actual, approx) << "%%" << std::endl;
        // std::cout << i << "\t" << error(actual, approx) << std::endl;
        // printf("%.20f\t%.20f\n", approx, error(actual, approx));


        errorV = error(actual, approx);
        if (errorV < bestError)
        {
            bestError = errorV;
            bestH = h;
        }


        printf("%.20f\t%.20f\n", h, error);
        // printf("%.20f\t%.20f\n", h, approx);
        printf("%.20f\t%.20f\n", h, truncationError(h));
        // h /= 2;
        h -= 0.001;
        // h *= (3/4.0);
        // h *= (3/4);
    }

    // std::cout << std::numeric_limits<float>::epsilon() << std::endl;

    // std::cout << centeredDifference(x, h, &f) << std::endl;
    // std::cout << h << std::endl;
    // printf("%.20f\n", hOpt());


    // std::cout << std::fixed << std::setprecision(20) << std:: 

    // std::cout << "hOpt(): " << hOpt() << std::endl;
    // std::cout << "bestH : " << bestH << std::endl;
    // std::cout << "bestError: " << bestError << std::endl;

    
    exit(0);
}
