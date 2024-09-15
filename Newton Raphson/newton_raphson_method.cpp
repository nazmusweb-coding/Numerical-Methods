#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

//-----------------------------------Function Definitions----------------------------------
// Function to compute the value of f(X) = 2*X^2 - 5*X + 3
double f(double X)
{
    return 2 * pow(X, 2) - 5*X + 3;
}

// Function to compute the derivative of f(X), f'(X) = 4*X - 5
double f1(double X)
{
    return 4*X - 5;
}

void newton_raphson_method(double X)
{
    int iteration = 1;                                                              // Initialize the iteration counter
    while (true)
    {
        cout << fixed << setprecision(5) << iteration << ' ' << X << endl;          // Print the current iteration number and X value
        double Xnew = X - f(X)/f1(X);                                               // Compute the new value of X using the Newton-Raphson formula
        if (fabs(X - Xnew) < 1e-6)                                                  // Check if the difference between the current and new X is smaller than the tolerance
        {
            break;                                                                  // Exit the loop if the difference is within the tolerance
        }
        X = Xnew;                                                                   // Update X with the new value
        iteration++;                                                                // Increment the iteration counter
    }
    cout << "Root found at iteration " << iteration << ", root is " << X << endl;   // Print the final result with the number of iterations and the root value
}

//-----------------------------------Main Program-------------------------------------------
int main(int argc, char **argv)
{
    double X;

    cout << "Enter value for X: ";                  // Prompt the user for the initial value of X
    cin >> X;                                       // Read the value of X from standard input
    newton_raphson_method(X);                       // Call the Newton-Raphson method with the user-provided initial value

    return 0;  // Exit the program
}