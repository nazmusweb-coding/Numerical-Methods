#include <iostream>  
#include <iomanip>         
#include <cmath>

using std::cout;
using std::cin;
using std::endl;  
using std::fixed;  
using std::setprecision; 

const double pi = 3.141592653589793;        // Define the constant pi with high precision

//----------------------------------------------Function Definitions--------------------------------------------
// Define the function f(x, y) = x^2 * y + x * y^2
double f(double x, double y)
{
    return pow(x, 2) * y + x * pow(y, 2);
}

// Compute the integral of f(x, y) using Simpson's 1/3 double integration rule
void simpsons1_3double_integration_rule(double lower_limit_x, double upper_limit_x, 
                                        double lower_limit_y, double upper_limit_y, 
                                        int number_of_divisions_x, 
                                        int number_of_divisions_y)
{
    double ax = lower_limit_x;              // Set the lower limit for x
    double bx = upper_limit_x;              // Set the upper limit for x
    double ay = lower_limit_y;              // Set the lower limit for y
    double by = upper_limit_y;              // Set the upper limit for y
    int nx = number_of_divisions_x;         // Set the number of divisions for x
    int ny = number_of_divisions_y;         // Set the number of divisions for y
    double hx = (bx - ax) / nx;             // Compute the width of each interval in x
    double hy = (by - ay) / ny;             // Compute the width of each interval in y
    double S = 0;                           // Initialize the sum for the integration

    for (int i = 0; i <= ny; i++)           // Iterate over the y intervals
    {
        int p;                              // Weight factor for the y interval
        if (i == 0 || i == ny)              // First or last interval
        {
            p = 1;
        }
        else if (i % 2 == 1)                // Odd interval
        {
            p = 4;
        }
        else                                // Even interval
        {
            p = 2;
        }

        for (int j = 0; j <= nx; j++)       // Iterate over the x intervals
        {
            int q;                          // Weight factor for the x interval
            if (j == 0 || j == nx)          // First or last interval
            {
                q = 1;
            }
            else if (j % 2 == 1)            // Odd interval
            {
                q = 4;
            }
            else                            // Even interval
            {
                q = 2;
            }
            S += p * q * f(ax + j * hx, ay + i * hy);   // Compute the function value at (x, y) and accumulate weighted sum
        }
    }
    double Integral = ((hx * hy) / 9) * S;  // Compute the integral using Simpson's 1/3 double integration formula
    cout << fixed << setprecision(16) << "Integral " << Integral << " [using simpson's 1/3 double integration rule]" << endl;   // Output the result with fixed precision
}

//--------------------------------------------------Main Program------------------------------------------------
int main(int argc, char **argv)
{
    // Define the integration limits and number of divisions
    double lower_limit_x = 1;
    double upper_limit_x = 2;
    double lower_limit_y = -1;
    double upper_limit_y = 1;
    // Compute and print the integral using Simpson's 1/3 double integration rule
    simpsons1_3double_integration_rule(lower_limit_x, upper_limit_x, lower_limit_y, upper_limit_y, 10, 10);

    return 0; // End of the program
}