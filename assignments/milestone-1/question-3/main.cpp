#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

std::vector<std::tuple<int, double>> buildData()
{
    std::vector<std::tuple<int, double>> data;

    data.push_back(std::make_tuple(0, 0    ));
    data.push_back(std::make_tuple(2, 1.9  ));
    data.push_back(std::make_tuple(4, 2    ));
    data.push_back(std::make_tuple(6, 2    ));
    data.push_back(std::make_tuple(8, 2.4  ));
    data.push_back(std::make_tuple(10, 2.6 ));
    data.push_back(std::make_tuple(12, 2.25));
    data.push_back(std::make_tuple(14, 1.12));
    data.push_back(std::make_tuple(16, 0   ));

    return data;
}

double trapezoidal(std::vector<std::tuple<int, double>> data, int h)
{
    // int h = std::get<0>(data[b]) - std::get<0>(data[a]);


    double result = 0;

    // maybe data.size() - 1
    for (int i = 0; i < data.size(); i += h)
    {
        result += std::get<1>(data[i * h]) + std::get<1>(data[(i + 1) * h]);
    }

    // return (h / 2) * (std::get<1>(data[b]) + std::get<1>(data[a]));
    return (h / 2) * result;
}

void displayTable(double** table, int n) 
{
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < i + 1; j ++)
        {
            std::cout << table[i][j] << " ";
        }

        std::cout << std::endl;
    }
}


double integrate(std::vector<std::tuple<int, double>> data)
{
    int n = 4;
    int h = 8;

    // stopping criterion of 1%
    double Es = 1.0;

    double** table = new double* [n];
    bool finished = false;

    for (int i = 0; !finished && i < n; i ++)
    {
        table[i] = new double[i + 1];
        table[i][0] = trapezoidal(data, h);

        for (int j = 1; !finished && j <= i; j ++)
        {
            table[i][j] = table[i][j - 1] + (table[i][j - 1] - table[i - 1][j - 1]) / (pow(4, j) - 1);

            if ((fabs(table[i][j] - table[i][j - 1]) / table[i][j]) * 100 < Es)
            {
                finished = true;
                std::cout << "Done!" << std::endl;
            }
        }

        h /= 2;



        // for (int j = 8; j > 2; j /= 2)
        // {
        //     table[i][0] = trapezoidal(data, 0, j);
        // }
    }

    // calculate column 1
    // std::cout << trapezoidal(data, 8) << std::endl;
    // std::cout << trapezoidal(data, 4) << std::endl;
    // std::cout << trapezoidal(data, 2) << std::endl;
    // std::cout << trapezoidal(data, 1) << std::endl;

    displayTable(table, n);

    // return table[0][0];
    return 1.0;
}

int main(int argc, char** argv)
{
    std::vector<std::tuple<int, double>> data = buildData();

    integrate(data);

    exit(0);
}