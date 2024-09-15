#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

//----------------------------------------------Function Definitions--------------------------------------------
// Define the function f(x) for which we will compute the derivatives
double f(double x)
{
    return 0.1 * pow(x, 5) - 0.2 * pow(x, 3) + 0.1 * x - 0.2;
}

// Compute forward differences for the function f(x) at point x with step size h
void forward_differences(double x, double h)
{
    double dff1 = (f(x + h) - f(x)) / h;                                                                    // First derivative
    double dff2 = (f(x + 2 * h) - 2 * f(x + h) + f(x)) / pow(h, 2);                                         // Second derivative
    double dff3 = (f(x + 3 * h) - 3 * f(x + 2 * h) + 3 * f(x + h) - f(x)) / pow(h, 3);                      // Third derivative
    double dff4 = (f(x + 4 * h) - 4 * f(x + 3 * h) + 6 * f(x + 2 * h) - 4 * f(x + h) + f(x)) / pow(h, 4);   // Fourth derivative

    cout << fixed << setprecision(6) 
         << "f'(" << x << ") = " << dff1 << endl
         << "f''(" << x << ") = " << dff2 << endl
         << "f'''(" << x << ") = " << dff3 << endl
         << "f''''(" << x << ") = " << dff4 << endl; // Output forward differences
}

// Compute central differences for the function f(x) at point x with step size h
void central_differences(double x, double h)
{
    double dfc1 = (f(x + h) - f(x - h)) / (2 * h);                                                          // First derivative
    double dfc2 = (f(x + h) - 2 * f(x) + f(x - h)) / pow(h, 2);                                             // Second derivative
    double dfc3 = (f(x + 2 * h) - 2 * f(x + h) + 2 * f(x - h) - f(x - 2 * h)) / pow(h, 3);                  // Third derivative
    double dfc4 = (f(x + 2 * h) - 4 * f(x + h) + 6 * f(x) - 4 * f(x - h) + f(x - 2 * h)) / pow(h, 4);       // Fourth derivative

    cout << "f'(" << x << ") = " << dfc1 << endl
         << "f''(" << x << ") = " << dfc2 << endl
         << "f'''(" << x << ") = " << dfc3 << endl
         << "f''''(" << x << ") = " << dfc4 << endl; // Output central differences
}

// Compute backward differences for the function f(x) at point x with step size h
void backward_differences(double x, double h)
{
    double dfb1 = (f(x) - f(x - h)) / h;                                                                    // First derivative
    double dfb2 = (f(x) - 2 * f(x - h) + f(x - 2 * h)) / pow(h, 2);                                         // Second derivative
    double dfb3 = (f(x) - 3 * f(x - h) + 3 * f(x - 2 * h) - f(x - 3 * h)) / pow(h, 3);                      // Third derivative
    double dfb4 = (f(x) - 4 * f(x - h) + 6 * f(x - 2 * h) - 4 * f(x - 3 * h) + f(x - 4 * h)) / pow(h, 4);   // Fourth derivative

    cout << "f'(" << x << ") = " << dfb1 << endl
         << "f''(" << x << ") = " << dfb2 << endl
         << "f'''(" << x << ") = " << dfb3 << endl
         << "f''''(" << x << ") = " << dfb4 << endl; // Output backward differences
}

//--------------------------------------------------Main Program------------------------------------------------
int main(int argc, char **argv)
{
    double x, h;
    cout << "Enter value for x and h: ";            // Prompt user for input
    cin >> x >> h;                                  // Read user input for x and h
    
    cout << "Forward differences:" << endl;
    forward_differences(x, h);                      // Compute and display forward differences
    
    cout << "Central differences:" << endl;
    central_differences(x, h);                      // Compute and display central differences
    
    cout << "Backward differences:" << endl;
    backward_differences(x, h);                     // Compute and display backward differences

    return 0; // End of program
}