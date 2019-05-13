#include <iostream>
#include <vector>

#include "./headers/Atom.hpp"
#include "./headers/Cluster.hpp"


int main(int argc, char** argv)
{
    Cluster cluster = Cluster(4);

    for (int i = 0; i < 100; i ++) 
    {
        cluster.randomize(0, 1);
        std::cout << cluster << std::endl;
    }

    // std::cout << "\nprintPoints" << std::endl;
    // cluster.printPoints();
    
    exit(0);
}