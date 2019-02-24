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
    double result = 1;

    for (int i = 0; i < terms; i ++)
    {
        result += (pow(x, i)) / factorial(i);
    }


    return result;
}

int main(int argc, char** argv) 
{
    double x = 0.5;
    double result;
    int terms = 1;

    while (terms < 5)
    {
        result = calculate(x, terms);
        printf("%f\n", result);
        terms ++;    

    }




    return 0;
}