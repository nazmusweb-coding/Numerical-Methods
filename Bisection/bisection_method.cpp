#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

//-----------------------------------Function Declarations----------------------------------
// Function to compute the value of f(x) = 2*x^2 - 5*x + 3
double f(double x)
{
    return 2 * pow(x, 2) - 5 * x + 3;
}

// Implementation of the Bisection Method to find the root of the function f(x)
void bisection_method(double a, double b)
{
    if (f(a) * f(b) >= 0)                                           // Check if f(a) and f(b) have the same sign
    {
        cout << "No roots exist within given interval" << endl;     // Print message if no roots exist in the interval
        exit(0);                                                    // Exit the program as the bisection method cannot proceed
    }
    int iteration = 1;                                              // Initialize the iteration counter

    while (true)
    {
        double c = (a + b) / 2;                                     // Compute the midpoint c of the interval [a, b]
        cout << fixed << setprecision(5) << iteration << ' ' << c << endl;  // Print the iteration number and midpoint c with 5 decimal places

        if (fabs(f(c)) < 1e-6)                                      // Check if the function value at c is within the tolerance
        {
            cout << "Root found at iteration " << iteration << ", root is " << c << endl;  // Print the root found and the number of iterations
            break;                                                  // Exit the loop as the root has been found
        }
        else if (f(a) * f(c) < 0)                                   // Check if the root is in the interval [a, c]
        {
            b = c;                                                  // Update b to c if the root is in [a, c]
        }
        else
        {
            a = c;                                                  // Update a to c if the root is in [c, b]
        }
        iteration++;                                                // Increment the iteration counter
    }
}

//-----------------------------------Main Program-------------------------------------------
int main(int argc, char **argv)
{
    double a, b;

    cout << "Enter value for a and b: " << endl;        // Prompt the user to enter values for a and b
    cin >> a >> b;                                      // Read the values of a and b from standard input
    bisection_method(a, b);                             // Call the bisection method with the provided values to find the root

    return 0;                                           // Exit the program
}
