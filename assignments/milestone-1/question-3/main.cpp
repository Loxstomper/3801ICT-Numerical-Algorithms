#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>
#include <cmath>

std::vector<std::tuple<int, double>> buildData()
{
    std::vector<std::tuple<int, double>> data;

    // (x, H)
    data.push_back(std::make_tuple(0 , 0   ));
    data.push_back(std::make_tuple(2 , 1.9 ));
    data.push_back(std::make_tuple(4 , 2   ));
    data.push_back(std::make_tuple(6 , 2   ));
    data.push_back(std::make_tuple(8 , 2.4 ));
    data.push_back(std::make_tuple(10, 2.6 ));
    data.push_back(std::make_tuple(12, 2.25));
    data.push_back(std::make_tuple(14, 1.12));
    data.push_back(std::make_tuple(16, 0   ));

    return data;
}

double trapezoidal(std::vector<std::tuple<int, double>> data, int h)
{
    // 0th and nth element
    double result = std::get<1>(data[0]) + std::get<1>(data[data.size() - 1]);

    // imbetween
    for (int i = 1; i < data.size() / h; i ++)
    {
        result += 2 * std::get<1>(data[i * h]);
    }

    // normally (h / 2) * result
    // but the value of h is already (h / 2) due to the table of values
    return h * result;
}

void displayTable(double** table, int n) 
{
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < i + 1; j ++)
        {
            // std::cout << table[i][j] << "\t";
            std::cout << std::setprecision(10) << table[i][j] << "\t";
        }

        std::cout << std::endl;
    }
}

double integrate(std::vector<std::tuple<int, double>> data)
{
    // maximum of 4 iterations can be done
    int n = 4;
    
    // h is really 16 but when converted to an index is 8
    int h = 8;

    // stopping criterion of 1%
    double Es = -1.0;

    // extrapolation table
    double** table = new double* [n];

    for (int i = 0; i < n; i ++)
    {
        table[i] = new double[i + 1];

        // initial row calculation
        table[i][0] = trapezoidal(data, h);

        for (int j = 1; j <= i; j ++)
        {
            // extrapolation 
            table[i][j] = table[i][j - 1] + (table[i][j - 1] - table[i - 1][j - 1]) / (pow(4, j) - 1);

            // stopping condition
            if ((fabs(table[i][j] - table[i][j - 1]) / table[i][j]) * 100 < Es)
            {
                // return the most recent value
                // displayTable(table, 4);
                return table[i][j];
            }
        }

        // halve h every iteration
        h /= 2;
    }

    // display extrapolation table if a value within 1% error was not found
    displayTable(table, 4);

    std::cout << "Value not found within 1%" << std::endl;
    return table[n][n + 1];
}

int main(int argc, char** argv)
{
    std::vector<std::tuple<int, double>> data = buildData();

    double integral = integrate(data);

    std::cout << std::setprecision(10) << integral << std::endl;



    exit(0);
}