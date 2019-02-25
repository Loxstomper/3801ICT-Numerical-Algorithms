#pragma once

#include "Point.hpp"
#include <math.h>
#include <iostream>

class Record
{
    public:
        Record(double time, double angle, double radius);
        Point toCartesian();
        double getTime();
        double getAngle();
        double getRadius();
        friend std::ostream &operator<<(std::ostream& stream, Record r);


    private:
        double time;
        double angle;
        double radius;
};