#pragma once
#include <iostream>

class Point
{
    public:
        Point();
        Point(double x, double y);
        double getX();
        double getY();
        friend std::ostream &operator<<(std::ostream& stream, Point p);
    
    private:
        double x;
        double y;
};