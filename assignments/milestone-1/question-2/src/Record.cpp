#include "./headers/Record.hpp"

Record::Record(int time, double angle, double radius)
{
    this->time = time;
    this->angle = angle;
    this->radius = radius;
}

Point Record::toCartesian(Record r)
{
    double x, y;

    x = r.radius * cos(r.angle);
    y = r.radius * sin(r.angle);

    return Point(x, y);
}