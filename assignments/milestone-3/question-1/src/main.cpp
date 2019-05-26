#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "./headers/Point.hpp"

#define WS 230000 / 2.205
#define TB 5300000 / 2.205
#define TS 1125000 / 2.205
#define RATE_OF_FUEL_LOSS 10236.22047244 / 2.205// dervived by dividing 1.3 * 10^6 by 127 seconds
#define SIG_DIGITS 5
#define SECANT_ACCURACY 0.5 * pow(10, 2 - SIG_DIGITS)

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

// std::vector<Point> generatePoints(double start, double wb, double stepSize, double n)
// {
//     std::vector<Point> points;

//     // probably use while loop to stop all the multiplications
//     // i dont like this because of the innacuracy
//     for (double i = 0; i < n; i ++)
//     {
//         points.push_back(Point(start + (stepSize * i), f(i, wb)));
//     }

//     return points;
// }

double secant(double x1, double x2, double wb) 
{ 
    double n = 0, xm, x0, c; 
    if (f(x1, wb) * f(x2, wb) < 0) { 
        do { 
            // calculate the intermediate value 
            x0 = (x1 * f(x2, wb) - x2 * f(x1, wb)) / (f(x2, wb) - f(x1, wb)); 
  
            // check if x0 is root of equation or not 
            c = f(x1, wb) * f(x0, wb); 
  
            // update the value of interval 
            x1 = x2; 
            x2 = x0; 
  
            // if x0 is the root of equation then break the loop 
            if (c == 0) 
                break; 

            xm = (x1 * f(x2, wb) - x2 * f(x1, wb)) / (f(x2, wb) - f(x1, wb)); 
        } while (fabs(xm - x0) >= 0.0001); 
  
        return x0;
    } else {
        throw "No root found in interval";
    }
} 
  

int main(int argc, char** argv)
{
    // full weight of tank + fuel
    double wb = (1.663 * pow(10, 6)) / 2.205;
    double y;

    Point points[128];

    for(int i = 0; i < 128; i++)
    {
        try {
            points[i].setX(i);
            points[i].setY(secant(0, 10, wb));
        } catch (const char* msg) {
            std::cerr << msg << std::endl;
        }

        wb -= RATE_OF_FUEL_LOSS;
    }

    for (int i = 0; i < 128; i ++) 
    {
        std::cout << points[i] << std::endl;
    }
    

    return 0;
}
