#include <iostream>
#include <iomanip>
#include <cmath>

#define GRAVITY 9.81
#define V0      20
#define X       35
#define Y0      2 
#define TARGET  1.0
#define DEBUG   0 

double f(double theta)
{
    theta *= (M_PI / 180.0);
    return tan(theta) * X - (GRAVITY / (2 * (V0 * V0) * (cos(theta) * cos(theta)))) * (X * X) + Y0;
}

double bisectionSearch(double target, double left, double right)
{
    double mid;
    double precision = 0.00001;

    // is the function increasing or decreasing within the tight bound
    int increasing = f(left) < f(right) ? 1 : 0;

    // until interval is small
    while ((right - left) >= precision) 
    {
        // calc mid point
        mid = (left + right) / 2;

        if (f(mid) == target) 
        {
            if (DEBUG) std::cout << "\nX found: " << mid << std::endl;

            break;
        }

        // if the function is increasing in value 
        //      if f(mid) is to the left of the target set left to midpoint
        //          else set right to midpoint
        // if the function is decreasing in value 
        //      if f(mid) is to the right of the target set left to midpoint
        //          else set right to midpoint
        increasing ? f(mid) < target ? left = mid : right = mid 
                   : f(mid) > target ? left = mid : right = mid;
    }

    if (DEBUG) std::cout << "\nPoint: " << mid << std::endl;

    return mid;
}

// true relative error
double error(double approx, double target) 
{
    return abs((target - approx) / target) * 100.0;
}


int main(int argc, char** argv)
{
    double target, x, v, e;

    // Point 1
    target = 1.0;
    x = bisectionSearch(target, 10, 40);
    v = f(x);
    e = error(v, target);

    std::cout << std::setprecision(10)
              << "Point 1" << "\n"
              << "X    : " << x << "\n"
              << "Value: " << v << "\n"
              << "Error: " << e << std::endl;

    // Point 2 
    target = 1.0;
    x = bisectionSearch(target, 40, 70);
    v = f(x);
    e = error(v, target);

    std::cout << std::setprecision(10) << "\n"
              << "Point 2" << "\n"
              << "X    : " << x << "\n"
              << "Value: " << v << "\n"
              << "Error: " << e << std::endl;

    return 0;
}