#include <iostream>
#include "./headers/Record.hpp"
#include "./headers/Point.hpp"

int main(int argc, char** argv)
{
    Point a = Point(1, 2);

    std::cout << a.getX() << " " << a.getY() << std::endl;
    exit(0);
}