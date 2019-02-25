#pragma once

#include "Point.hpp"
#include <math.h>

class Record
{
    public:
        Record(int time, double angle, double radius);
        Point toCartesian(Record r);

    private:
        int time;
        double angle;
        double radius;
};