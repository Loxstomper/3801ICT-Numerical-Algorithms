#include <iostream>
#include <vector>

#include "./headers/Atom.hpp"
#include "./headers/Cluster.hpp"


int main(int argc, char** argv)
{
    Cluster cluster = Cluster(4);
    cluster.randomize(10, 50);

    std::cout << cluster << std::endl;

    // std::cout << "\nprintPoints" << std::endl;
    // cluster.printPoints();
    
    exit(0);
}