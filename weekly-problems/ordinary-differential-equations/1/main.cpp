#include <iostream>
#include <cmath>

double df(double x)
{
    return -2 * pow(x, 3) + 12 * pow(x, 2) - 20 * x + 8.5;
}

int main(int argc, char** argv)
{
    double x = 0, y = 1;

    std::cout << x << " " << y << std::endl;

    for(int i = 0; i < 8; i++)
    {
        y += df(x) * 0.5;
        x += 0.5;

        std::cout << x << " " << y << std::endl;
    }
    
    exit(0);
}