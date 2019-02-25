#include "./headers/Record.hpp"

Record::Record(double time, double angle, double radius)
{
    this->time = time;
    this->angle = angle;
    this->radius = radius;
}

double Record::getTime()
{
    return this->time;
}

double Record::getAngle()
{
    return this->angle;
}

double Record::getRadius()
{
    return this->radius;
}

Point Record::toCartesian()
{
    double x, y;

    x = this->radius * cos(this->angle);
    y = this->radius * sin(this->angle);

    return Point(x, y);
}

std::ostream &operator<<(std::ostream& stream, Record r)
{
    stream << r.getTime() << " " << r.getAngle() << " " << r.getRadius();

    return stream;
}
