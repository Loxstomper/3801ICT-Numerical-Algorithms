#pragma once

#include <iostream>

#include "Point.hpp"

class Atom
{
    public:
        Atom();
        Atom(double x, double y, double z);

        void updatePosition(double x, double y, double z);
        Point getPoint();

        double getEnergy(Atom a);

        friend std::ostream &operator<<(std::ostream& stream, Atom a);

    private:
        Point point;
};