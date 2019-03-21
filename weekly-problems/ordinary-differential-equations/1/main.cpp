#include <iostream>
#include <cmath>

double df(double x)
{
    return -2 * pow(x, 3) + 12 * pow(x, 2) - 20 * x + 8.5;
}

int main(int argc, char** argv)
{
    double stepSize = 0.5;
    double x = 0, yPrev = 1, y;

    std::cout << x << " " << yPrev << "\n" << std::endl;

    for(int i = 0; i < 8; i++)
    {
        y = yPrev + df(x) * stepSize * 0.5;
        yPrev = y;
        x += stepSize;

        std::cout << x << "\t" << y << std::endl;
    } 

    std::cout << "Done: " << y << std::endl;
    
    exit(0);
}