#include "./headers/Point.hpp"

Point::Point()
{

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

std::ostream &operator<<(std::ostream& stream, Point p)
{
    stream << p.getX() << " " << p.getY();

    return stream;
}
