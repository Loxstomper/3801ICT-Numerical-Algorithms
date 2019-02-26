#include <iostream>
#include <vector>

#include "./headers/Record.hpp"
#include "./headers/Point.hpp"

std::vector<Record> buildRecords()
{
    std::vector<Record> records;

    records.push_back(Record(200, 0.75, 5120));
    records.push_back(Record(202, 0.72, 5370));
    records.push_back(Record(204, 0.70, 5560));
    records.push_back(Record(206, 0.68, 5800));
    records.push_back(Record(208, 0.67, 6030));
    records.push_back(Record(210, 0.66, 6240));

    return records;
}

double firstDerivative(Record a, Record b)
{
    double h = abs(a.getTime() - b.getTime());

    Point aPoint = a.toCartesian();
    Point bPoint = b.toCartesian();

    double xPrime = (aPoint.getX() - bPoint.getX()) / h;
    double yPrime = (aPoint.getY() - bPoint.getY()) / h;

    double velocity = sqrt(pow(xPrime, 2) + pow(yPrime, 2));

    return velocity;
}

double secondDerivative(double v1, double v2, double h)
{
    return (v1 - v2) / h;
}

std::vector<double> calcVelocities(std::vector<Record> r)
{
    std::vector<double> velocities;

    double v;

    for (int i = 1; i < r.size(); i ++) 
    {
        v = firstDerivative(r[i - 1], r[i]);

        velocities.push_back(v);
    }

    return velocities;
}

std::vector<double> calcAccelerations(std::vector<double> v, double h)
{
    std::vector<double> accelerations;

    double a;

    for (int i = 1; i < v.size(); i ++) 
    {
        a = secondDerivative(v[i - 1], v[i], h);

        accelerations.push_back(a);
    }

    return accelerations;
}

int main(int argc, char** argv)
{
    std::vector<Record> records = buildRecords();

    // for (Record r: records) 
    // {
    //     std::cout << r.getTime() << " " << r.getAngle() << " " << r.getRadius() << std::endl;
    // }

    // std::cout << firstDerivative(records[0], records[1]) << std::endl;

    double v1 = firstDerivative(records[0], records[1]);
    double v2 = firstDerivative(records[1], records[2]);

    double a1 = secondDerivative(v1, v2, 2.0);

    std::vector<double> velocities = calcVelocities(records);
    std::vector<double> accelerations = calcAccelerations(velocities, 2.0);

    std::cout << "V" << std::endl;

    for (double v: velocities)
    {
        std::cout << v << std::endl;
    }

    std::cout << "A" << std::endl;

    for (double a: accelerations)
    {
        std::cout << a << std::endl;
    }

    exit(0);
}