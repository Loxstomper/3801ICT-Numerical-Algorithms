#pragma once

#include "Point.hpp"
#include <math.h>

class Record
{
    public:
        Record(double time, double angle, double radius);
        Point toCartesian();
        double getTime();
        double getAngle();
        double getRadius();

    private:
        double time;
        double angle;
        double radius;
};