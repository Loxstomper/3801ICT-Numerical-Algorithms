#include <iostream>
#include <iomanip>
#include <cmath>

// values given on task sheet
#define f 60.0
#define E 1.25 * pow(10.0, 8.0)
#define I 0.05
#define L 30.0

// True y found online (wolfram alpha) 
// y''   = f2()
// y'(0) = 0
// y(0)  = 0
double a(double x) 
{
	return (x * x) * (4.0 * pow(10.0, -7.0) * (x * x) - 0.000048 * x + 0.00216);
}

// True y' found by deriving true y
double a1(double x) 
{
	return 0.0000016 * pow(x, 3) - 0.000144 * pow(x, 2) + 0.00432 * x;
}

// Equation 1: dy/dx = z
double f1(double x, double y, double z) 
{
	return z;
}

// Equation 2: d2y/d2x 
double f2(double x, double y, double z) 
{
	return (f / (2 * E * I)) * pow(L - x, 2);
}

void euler(double x, double& y, double& z, double h) 
{
	static double ky1, kz1;
	
	ky1 = f1(x, y, z) * h;
	kz1 = f2(x, y, z) * h;
	
	y += ky1;
	z += kz1;
}

void midPoint(double x, double& y, double& z, double h) 
{
	// New y, where eq(1) = f1()
	// New dydz, where eq(2) = f2()
	static double ky1, ky2, kz1, kz2;
	
	ky1 = f1(x, y, z) * h;
	kz1 = f2(x, y, z) * h;
	
	ky2 = f1(x + (h / 2.0), y + (ky1 / 2.0), z + (kz1 / 2.0));
	kz2 = f2(x + (h / 2.0), y + (ky1 / 2.0), z + (kz1 / 2.0));
	
	y += ky2 * h;
	z += kz2 * h;
}

void huens(double x, double& y, double& z, double h) 
{
	static double ky1, ky2, kz1, kz2;
	
	ky1 = f1(x, y, z);
	kz1 = f2(x, y, z);
	
	ky2 = f1(x + h, y + (h * ky1), z + (h * kz1));
	kz2 = f2(x + h, y + (h * ky1), z + (h * kz1));
	
	y += 0.5 * (ky1 + ky2) * h;
	z += 0.5 * (kz1 + kz2) * h;
}

void rk4(double x, double& y, double& z, double h) 
{
	static double ky1, ky2, ky3, ky4, kz1, kz2, kz3, kz4;
	
	ky1 = f1(x, y, z) * h;
	kz1 = f2(x, y, z) * h;
	
	ky2 = f1(x + (0.5 * h), y + (0.5 * ky1), z + (0.5 * kz1)) * h;
	kz2 = f2(x + (0.5 * h), y + (0.5 * ky1), z + (0.5 * kz1)) * h;
	
	ky3 = f1(x + (0.5 * h), y + (0.5 * ky2), z + (0.5 * kz2)) * h;
	kz3 = f2(x + (0.5 * h), y + (0.5 * ky2), z + (0.5 * kz2)) * h;
	
	ky4 = f1(x + h, y + ky3, z + kz2) * h;
	kz4 = f2(x + h, y + ky3, z + kz2) * h;
	
	y = y + 1/6.0 * (ky1 + (2 * ky2) + (2 * ky3) + ky4);
	z = z + 1/6.0 * (kz1 + (2 * kz2) + (2 * kz3) + kz4);
}

double error(double approx, double target)
{
	return abs((target - approx) / target) * 100.0;
}

int main(int argc, char** argv) 
{
	double xMax = 0.5;
	double h    = 0.125;
	// double h    = 1;
	
	// euler, midpoint, huen, rk4
	double Y[] = {0.0, 0.0, 0.0, 0.0};
	double Z[] = {0.0, 0.0, 0.0, 0.0};

	double ax, a1x;

	for (double i = 0; i < 30; i += h)
	{
		euler   (i, Y[0], Z[0], h);
		midPoint(i, Y[1], Z[1], h);
		huens   (i, Y[2], Z[2], h);
		rk4     (i, Y[3], Z[3], h);

		// calculate analytical values
		ax  = a(i + h);
		a1x = a1(i + h);
		
		std::cout << std::setprecision(10)
		// << "\n\nx = " << i + h << "\n"
		// << "Euler      : y(x) = " << Y[0] << "\ty'(x) = " << Z[0] << "\terror(y) = " << error(Y[0], ax) << "\terror(y') = " << error(Z[0], a1x) <<"\n"
		// << "Midpoin    : y(x) = " << Y[1] << "\ty'(x) = " << Z[1] << "\terror(y) = " << error(Y[1], ax) << "\terror(y') = " << error(Z[1], a1x) <<"\n"
		// << "Huen       : y(x) = " << Y[2] << "\ty'(x) = " << Z[2] << "\terror(y) = " << error(Y[2], ax) << "\terror(y') = " << error(Z[2], a1x) <<"\n"
		// << "Rk4        : y(x) = " << Y[3] << "\ty'(x) = " << Z[3] << "\terror(y) = " << error(Y[3], ax) << "\terror(y') = " << error(Z[3], a1x) <<"\n"
		// << "Analytical : y(x) = " << ax   << "\ty'(x) = " << a1x  << "\terror(y) = 0\terror(y') = 0"  << std::endl;
		<< i + h << " " << Y[0] << " " << Y[1] << " " << Y[2] << " " << Y[3] << " " << ax << std::endl;
		// << i << " " << Y[0] << " " << Y[1] << " " << Y[2] << " " << Y[3] << std::endl;
		// << i + h << " " << error(Y[0], ax) << " " << error(Y[1], ax) << " " << error(Y[2], ax) << " " << error(Y[3], ax) << " " << ax << std::endl;
	}

	// for (double i = 0; i < 30; i += h)
	// {
	// 	rk4     (i, Y[0], Z[0], h, 0.05);
	// 	rk4     (i, Y[1], Z[1], h, 0.10);
	// 	rk4     (i, Y[2], Z[2], h, 0.15);
	// 	rk4     (i, Y[3], Z[3], h, 0.20);
	// 	std::cout << std::setprecision(10)
	// 	<< i + h << " " << Y[0] << " " << Y[1] << " " << Y[2] << " " << Y[3] << " " << std::endl;
	// }
	
	return 0;
}
