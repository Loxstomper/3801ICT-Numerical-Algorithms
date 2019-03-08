#include <iostream>
#include <vector>
#include <tuple>

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

// f'(x) = (f(x + h) - f(x - h)) / 2h
std::tuple<double, double> firstDerivative(Record a, Record b)
{
    // this is over 3 points, the value is actually 2 per point 
    double h = abs(a.getTime() - b.getTime()) / 2;

    Point aPoint = a.toCartesian();
    Point bPoint = b.toCartesian();

    double xPrime = (bPoint.getX() - aPoint.getX()) / (2 * h);
    double yPrime = (bPoint.getY() - aPoint.getY()) / (2 * h);

    double velocity = sqrt(pow(xPrime, 2) + pow(yPrime, 2));

    return std::make_tuple(xPrime, yPrime);
}

std::tuple<double, double> secondDerivative(std::tuple<double, double> v1, std::tuple<double, double> v2, double h)
{
    double xPrime = (std::get<0>(v2) - std::get<0>(v1)) / (2 * h);
    double yPrime = (std::get<1>(v2) - std::get<1>(v1)) / (2 * h);

    return std::make_tuple(xPrime, yPrime);
}

std::vector<std::tuple<double, double>> calcVelocities(std::vector<Record> r)
{
    std::vector<std::tuple<double, double>> velocities;

    std::tuple<double, double> v;

    for (int i = 1; i < r.size() -1; i ++) 
    {
        v = firstDerivative(r[i - 1], r[i + 1]);

        velocities.push_back(v);
    }

    return velocities;
}

std::vector<std::tuple<double, double>> calcAccelerations(std::vector<std::tuple<double, double>> v, double h)
{
    std::vector<std::tuple<double, double>> accelerations;

    std::tuple<double, double> a;

    for (int i = 1; i < v.size() - 1; i ++) 
    {
        a = secondDerivative(v[i - 1], v[i + 1], h);

        accelerations.push_back(a);
    }

    return accelerations;
}

void displayPoints(std::vector<Record> records)
{
    std::cout << "\n\t\tPoints" << std::endl;
    std::cout << "Time\tR\tθ\tX\tY" << std::endl;

    Point p;

    for (Record r: records)
    {
        p = r.toCartesian();

        std::cout << r.getTime() << "\t" << r.getRadius() << "\t" << r.getAngle() << "\t" << p.getX() << "\t" << p.getY() << std::endl;
    }
}

int main(int argc, char** argv)
{
    std::vector<Record> records = buildRecords();

    displayPoints(records);

    std::vector<std::tuple<double, double>> velocities = calcVelocities(records);
    std::vector<std::tuple<double, double>> accelerations = calcAccelerations(velocities, 2.0);


    std::cout << "\n\tVelocity" << std::endl;
    std::cout << "X\t\tY" << std::endl;

    for (std::tuple<double, double> v: velocities)
    {
        std::cout << std::get<0>(v) << "\t\t" << std::get<1>(v) << std::endl;
    }

    std::cout << "\n\tAcceleration" << std::endl;
    std::cout << "X\t\tY" << std::endl;

    for (std::tuple<double, double> a: accelerations)
    {
        std::cout << std::get<0>(a) << "\t" << std::get<1>(a) << std::endl;
    }

    std::cout << std::endl;

    exit(0);
}