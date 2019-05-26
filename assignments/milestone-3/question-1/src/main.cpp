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

double fDrag(double x, double wb)
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

double acceleration(double theta, double wb)
{
    // F = ma
    // F = Net Thrust = TB + TR 
    // m = TB + TS

    return (TB + TS) / (WS + wb);
}

void velocity(double* v, double* a, int n)
{
    // integrate tho?

    // using kinematics formula
    // v = u + at
    // t = 1

    v[0] = 0;

    for (int i = 1; i < n; i ++)
    {
        v[i] = v[i - 1] + a[i];
    }
}

void displacement(double* s, double* v, double* a, int n)
{
    // kinematics formula
    // s = v[i - 1] * t + 0.5 (at)^2
    // t = 1

    s[0] = 0;

    for (int i = 1; i < n; i ++)
    {
        s[i] = s[i - 1] + v[i - 1] + 0.5 * (a[i] * a[i]);
    }
}
  

int main(int argc, char** argv)
{
    // full weight of tank + fuel
    double wb = (1.663 * pow(10, 6)) / 2.205;
    double y;

    Point points[128];
    double accelerations[128];
    double velocities[128];
    double displacements[128];

    for(int i = 0; i < 128; i++)
    {
        try {
            points[i].setX(i);
            points[i].setY(secant(0, 10, wb));
        } catch (const char* msg) {
            std::cerr << msg << std::endl;
        }

        // std::cout << points[i] << " Acceleration: " << acceleration(points[i].getY(), wb) << std::endl;
        // std::cout << points[i] << " " << acceleration(points[i].getY(), wb) << std::endl;

        accelerations[i] = acceleration(points[i].getY(), wb);

        wb -= RATE_OF_FUEL_LOSS;
    }

    velocity(velocities, accelerations, 128);
    displacement(displacements, velocities, accelerations, 128);

    for (int i = 0; i < 128; i ++) 
    {
        std::cout << points[i] << "\t" << accelerations[i] << "\t" << velocities[i] << "\t" << displacements[i] << std::endl;
    }

    // DO LAGRANGE

    // GET ACCELERATION

    // LAGRANGE ON ACCELERATION

    // Integrate the acceleration to get velocity

    // Use this velocity to incorporate drag

    // Find acceleration 
    

    return 0;
}
