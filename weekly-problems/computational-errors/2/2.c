#include <stdio.h>
#include <math.h>

int factorial(int n)
{
    if (n == 0) 
        return 1;

    return n * factorial(n - 1);
}

double calculate(double x, int terms)
{
    // double result = 1;
    double result = 0;

    for (int i = 0; i < terms; i ++)
    {
        result += (pow(x, i)) / factorial(i);
    }

    return result;
}

int main(int argc, char** argv) 
{
    double x = 0.5;
    double previous = 999;
    double current;
    int terms = 1;

    // erro 0.05% for 3 sig digits
    double Es = 0.05;

    // approx relative error
    double are = 99;

    while (are > Es)
    {
        current = calculate(x, terms);
        are = abs((current - previous) / current) * 100;

        printf("%d %f %f\n", terms, current, are);

        previous = current;
        terms ++;    
    }




    return 0;
}