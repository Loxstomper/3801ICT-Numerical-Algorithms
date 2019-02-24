#include <iostream>

float sum(float n, int times)
{
    float r = n;

    for (int i = 0; i < times; i ++)
    {
        r += n;
    }

    return r;
}

double sum(double n, int times)
{
    float r = n;

    for (int i = 0; i < times; i ++)
    {
        r += n;
    }

    return r;
}

int main(int argc, char** argv)
{
    float  a = 1;
    float  b = 0.00001;
    double c = 0.00001;

    int times = 100000;

    std::cout << sum(a, times) << std::endl;
    std::cout << sum(b, times) << std::endl;
    std::cout << sum(c, times) << std::endl;









    return 0;
}