#include <iostream>
#include <vector>

#include "./headers/Atom.hpp"
#include "./headers/Cluster.hpp"


int main(int argc, char** argv)
{
    Cluster cluster = Cluster(100);

    // for (int i = 0; i < 100; i ++) 
    // {
        // cluster.randomize(0, 100);
        // std::cout << cluster << std::endl;
    // }

    cluster.randomize(0, 100);
    cluster.printPoints();

    // std::cout << "\nprintPoints" << std::endl;
    // cluster.printPoints();
    
    exit(0);
}