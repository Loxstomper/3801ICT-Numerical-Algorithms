#include <stdlib.h>
#include <iostream>


double f(double x) 
{
    return x * x - 3;
}

double search(double left, double right)
{
    double mid = left;
    double precision = 0.0001;

    // until interval is small
    while ((right - left) >= precision) 
    {
        mid = (left + right) / 2;

        if (abs(f(mid)) <= precision) 
        {
            break;
        }

        if (f(mid) * f(left) < 0) 
        {
            right = mid;
        } 
        else 
        {
            left = mid;
        }
    }

    return mid;
}



int main(int argc, char** argv)
{
    std::cout << search(0, 2) << std::endl;
    return 0;
}
