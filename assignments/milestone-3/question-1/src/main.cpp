#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "./headers/Point.hpp"

#define WS 230000
#define TB 5300000
#define TS 1125000
#define RATE_OF_FUEL_LOSS 10236.22047244 // dervived by dividing 1.3 * 10^6 by 127 seconds

double f(double x, double wb)
{
    x *= M_PI / 180;
    return (((TB - wb) * 4) + (TS * sin(x) * 38)) - ((TS * cos(x)) - WS) * 24;
}

std::vector<Point> generatePoints(double start, double wb, double end, double n)
{
    std::vector<Point> points;
    double stepSize = abs(end - start) / n;

    // i dont like this because of the innacuracy
    for (double i = start; i < end; i += stepSize)
    {
        points.push_back(Point(i, f(i, wb)));
    }

    return points;
}

std::vector<Point> generatePoints(double start, double wb, double stepSize, double n)
{
    std::vector<Point> points;

    // probably use while loop to stop all the multiplications
    // i dont like this because of the innacuracy
    for (double i = 0; i < n; i ++)
    {
        points.push_back(Point(start + (stepSize * i), f(i, wb)));
    }

    return points;
}

double secant(double a_x, double b_x, double wb)
{
    double mid_x, mid_y, a_y, b_y;
    double accuracy = 0.5 * pow(10, 2 - 5);

    a_y = f(a_y, wb);
    b_y = f(b_y, wb);

    if (a_y * b_y < 0)
    {
        do {
            mid_x = (a_x * b_y - b_x * a_y) / (b_y - a_y); 
        } while (fabs())
    }
}

int main(int argc, char** argv)
{
    Point a = Point(1, 2);
    Point b = Point();

    std::cout << a.getX() << " " << a.getY() << std::endl;
    std::cout << b.getX() << " " << b.getY() << std::endl;

    // do claculation before liftoff

    for(int i = 0; i < 127; i++)
    {
        // subtract weight do secant
    }
    

    return 0;
}
