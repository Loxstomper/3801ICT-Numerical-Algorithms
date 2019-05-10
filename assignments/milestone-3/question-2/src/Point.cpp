#include "./headers/Point.hpp"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Point::getX()
{
    return this->x;
}

double Point::getY()
{
    return this->y;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

double Point::getDistance(Point p)
{
    return sqrt(pow(this->x - p.getX(), 2) + pow(this->y - p.getY(), 2));
}

std::ostream &operator<<(std::ostream& stream, Point p)
{
    stream << p.getX() << " " << p.getY();

    return stream;
}
