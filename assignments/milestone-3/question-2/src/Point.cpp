#include "./headers/Point.hpp"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = y;
}

double Point::getX()
{
    return this->x;
}

double Point::getY()
{
    return this->y;
}

double Point::getZ()
{
    return this->z;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::setZ(double z)
{
    this->z = z;
}

double Point::getDistance(Point p)
{
    return sqrt(pow(this->x - p.getX(), 2) + pow(this->y - p.getY(), 2) + pow(this->z - p.getZ(), 2));
}

std::ostream &operator<<(std::ostream& stream, Point p)
{
    stream << p.getX() << " " << p.getY() << " " << p.getZ();

    return stream;
}
