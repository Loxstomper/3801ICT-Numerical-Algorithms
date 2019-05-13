#pragma once

#include <iostream>
#include <cmath>

class Point
{
    public:
        Point();
        Point(double x, double y, double z);

        double getX();
        double getY();
        double getZ();
        void   setX(double x);
        void   setY(double y);
        void   setZ(double z);

        double getDistance(Point p);

        friend std::ostream &operator<<(std::ostream& stream, Point p);

    private:
        double x;
        double y;
        double z;
};
