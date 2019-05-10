#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Atom.hpp"

class Cluster
{
    public:
        Cluster(int size);
        ~Cluster();

        void randomize(double min, double max);

        double getEnergy();
        double getEnergyGradient(int i);

        int getSize();

        Atom getAtom(int i);

        void printPoints();
        friend std::ostream &operator<<(std::ostream& stream, Cluster c);
    
    private:
        int size;
        Atom* atoms;
};