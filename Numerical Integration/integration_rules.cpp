#include <iostream>  
#include <iomanip>         
#include <cmath>

using std::cout;           
using std::cin;           
using std::endl;          
using std::fixed;          
using std::setprecision;  

const double pi = 3.141592653589793;                    // Define the constant pi with high precision

//----------------------------------------------Function Definitions--------------------------------------------
// Define the function f(x) = x * sin(x)
double f(double x)
{
    return x * sin(x);
}

// Compute the integral of f(x) using the trapezoidal rule
void trapezoidal_rule(double lower_limit, double upper_limit, int number_of_divisions)
{
    double a = lower_limit;                             // Set the lower limit of integration
    double b = upper_limit;                             // Set the upper limit of integration
    int n = number_of_divisions;                        // Set the number of divisions for the trapezoidal rule
    double h = (b - a) / n;                             // Compute the width of each trapezoid
    double S = 0.5 * (f(a) + f(b));                     // Initialize the sum with the average of function values at the ends
    for (int i = 1; i < n; i++)                         // Iterate through the divisions
    {
        S += f(a + i * h);                              // Add the function value at each subdivision point
    }
    double Integral = h * S;                            // Compute the integral as the width times the sum
    cout << fixed << setprecision(16) << "Integral " << Integral << " [using trapezoidal rule]" << endl; // Output the result with fixed precision
}

// Compute the integral of f(x) using Simpson's 1/3 rule
void simpsons1_3rule(double lower_limit, double upper_limit, int number_of_divisions)
{
    double a = lower_limit;                             // Set the lower limit of integration
    double b = upper_limit;                             // Set the upper limit of integration
    int n = number_of_divisions;                        // Set the number of divisions for Simpson's 1/3 rule
    double h = (b - a) / n;                             // Compute the width of each interval
    double S = f(a) + f(b);                             // Initialize the sum with the function values at the ends
    for (int i = 1; i < n; i += 2)                      // Iterate over odd indices
    {
        S += 4 * f(a + i * h);                          // Add 4 times the function value at each odd index
    }
    for (int i = 2; i < n; i += 2)                      // Iterate over even indices
    {
        S += 2 * f(a + i * h);                          // Add 2 times the function value at each even index
    }
    double Integral = (h / 3) * S;                      // Compute the integral using Simpson's 1/3 rule formula
    cout << "Integral " << Integral << " [using simpson's 1/3 rule]" << endl; // Output the result
}

// Compute the integral of f(x) using Simpson's 3/8 rule
void simpsons3_8rule(double lower_limit, double upper_limit, int number_of_divisions)
{
    double a = lower_limit;                             // Set the lower limit of integration
    double b = upper_limit;                             // Set the upper limit of integration
    int n = number_of_divisions;                        // Set the number of divisions for Simpson's 3/8 rule
    double h = (b - a) / n;                             // Compute the width of each interval
    double S = f(a) + f(b);                             // Initialize the sum with the function values at the ends
    for (int i = 1; i < n; i += 3)                      // Iterate over indices with step 3
    {
        S += 3 * (f(a + i * h) + f(a + (i + 1) * h));   // Add 3 times the sum of function values at each set of 3 points
    }
    for (int i = 3; i < n; i += 3)                      // Iterate over indices with step 3 starting from 3
    {
        S += 2 * f(a + i * h);                          // Add 2 times the function value at each subsequent set of 3 points
    }
    double Integral = ((3 * h) / 8) * S;                // Compute the integral using Simpson's 3/8 rule formula
    cout << "Integral " << Integral << " [using simpson's 3/8 rule]" << endl; // Output the result
}

//--------------------------------------------------Main Program------------------------------------------------
int main(int argc, char **argv)
{
    double lower_limit = 0;                             // Set lower limit of integration
    double upper_limit = pi / 2;                        // Set upper limit of integration (π/2)
    trapezoidal_rule(lower_limit, upper_limit, 100);    // Compute and print integral using trapezoidal rule with 100 divisions
    simpsons1_3rule(lower_limit, upper_limit, 18);      // Compute and print integral using Simpson's 1/3 rule with 18 divisions
    simpsons3_8rule(lower_limit, upper_limit, 18);      // Compute and print integral using Simpson's 3/8 rule with 18 divisions

    return 0; // End of the program
}