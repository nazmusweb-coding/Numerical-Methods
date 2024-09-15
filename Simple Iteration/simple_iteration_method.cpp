#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

//-----------------------------------Function Declaration----------------------------------
void simple_iteration_method(double X)
{
    int iteration = 1;                                  // Initialize the iteration counter
    while (true)
    {
        cout << fixed << setprecision(5) 
             << iteration << ' ' << X << endl;          // Print the current iteration number and X value
        double Xnew = (2 * pow(X, 2) + 3) / 5;          // Compute the new value of X using the iteration formula
        if (X == Xnew)                                  // Check if the current value X is the same as the new value Xnew
        {
            break;                                      // Exit the loop if X and Xnew are the same
        }
        X = Xnew;                                       // Update X with the new value
        iteration++;                                    // Increment the iteration counter
    }
    cout << "Root found at iteration " << iteration << ", root is " << X << endl;  // Print the final result
}

//-----------------------------------Main Program-------------------------------------------
int main(int argc, char **argv)
{
    double X;
    cout << "Enter value for X: ";                 // Prompt user for the initial value of X
    cin >> X;                                      // Read the value of X from standard input
    simple_iteration_method(X);                    // Call the iteration method with the initial value

    return 0;
}