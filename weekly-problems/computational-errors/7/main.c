#include <stdio.h>
#include <math.h>

double calc_asc(int n)
{
    double result = 0;

    for (int i = 1; i < n; i ++)
    {
        result += ( 1 / pow(i, 4));
    }

    return result;
}

double calc_desc(int n)
{
    double result = 0;

    for (int i = n; i > 0; i --)
    {
        result += ( 1 / pow(i, 4));
    }

    return result;
}

int main(int argc, char** argv)
{
    int n = 10000;

    printf("%f \n", calc_asc(n));
    printf("%f \n", calc_desc(n));


    return 0;
}