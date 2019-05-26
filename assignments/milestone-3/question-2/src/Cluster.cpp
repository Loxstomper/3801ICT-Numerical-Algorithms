#include "./headers/Cluster.hpp"

Cluster::Cluster(int size)
{
    this->size = size;
    this->atoms = new Atom[size];

    // check if successful?
}

Cluster::~Cluster()
{
    delete[] this->atoms;
}

void Cluster::randomize(double min, double max)
{
    double range = max - min;
    double x, y, z;

    srand(time(NULL));

    for (int i = 0; i < this->size; i ++)
    {
        x = min + (rand() / (RAND_MAX / range));
        y = min + (rand() / (RAND_MAX / range));
        z = min + (rand() / (RAND_MAX / range));

        this->atoms[i].updatePosition(x, y, z);
    }
}

// MAYBE STORE THIS AS VARIABLE IN CASE NEEDS TO BE COMPUTED A LOT
double Cluster::getEnergy()
{
    double energy = 0.0f;

    for (int i = 0; i < this->size; i ++)
    {
        for (int j = i + 1; j < this->size; j ++)
        {
            energy += this->atoms[i].getEnergy(this->atoms[j]);
        }
    }

    return energy;
}

double Cluster::getEnergyGradient(int i)
{
    double energy = 0;

    for (int i = 0; i < this->size; i ++)
    {
        for (int j = 0; j < this->size; j ++)
        {
            if (i != j)
            {
                energy += 1;
            }
        }
    }

}

int Cluster::getSize()
{
    return this->size;
}

Atom Cluster::getAtom(int i)
{
    return this->atoms[i];
}

void Cluster::printPoints()
{
    for (int i = 0; i < this->size; i ++)
    {
        std::cout << this->atoms[i] << std::endl;
    }
}

std::ostream &operator<<(std::ostream& stream, Cluster c)
{
    stream << "Size: " << c.getSize() << " Energy: " << c.getEnergy();

    // stream << "i point energy_gradient\n";

    // for (int i = 0; i < size; i ++)
    // {
    //     // stream << i << " " << c.getAtom(i) << " ";
    // }

    return stream;
}
    