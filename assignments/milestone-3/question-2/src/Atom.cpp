#include "./headers/Atom.hpp"

Atom::Atom()
{
    this->point = Point();
}

Atom::Atom(double x, double y, double z)
{
    this->point = Point(x, y, z);
}

void Atom::updatePosition(double x, double y, double z)
{
    this->point.setX(x);
    this->point.setY(y);
    this->point.setZ(z);
}

Point Atom::getPoint()
{
    return this->point;
}

double Atom::getEnergy(Atom a)
{
    double distance = this->point.getDistance(a.getPoint());
    
    return (pow(distance, -12) - pow(2 * distance, -6));
}

std::ostream &operator<<(std::ostream& stream, Atom a)
{
    stream << a.getPoint();

    return stream;
}