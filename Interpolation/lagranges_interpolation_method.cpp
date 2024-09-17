#include <iostream>

using std::cout; 
using std::cin;  
using std::endl;   

//------------------------------------------------------------Function Definitions-----------------------------------------------------------
void lagranges_interpolation(double x[], double y[], int n, double X)
{
    double Y = 0;                                       // Initialize the interpolated value Y to 0

    for (int i = 0; i < n; i++)                         // Loop through each data point to compute the Lagrange interpolation
    {
        double L = 1;                                   // Initialize the Lagrange basis polynomial L_i to 1 for the current i

        for (int j = 0; j < n; j++)                     // Compute the Lagrange basis polynomial L_i(X)
        {
            if (j != i)                                 // Skip the case where j == i
            {
                L *= (X - x[j]) / (x[i] - x[j]);        // Update L by multiplying with (X - x[j]) / (x[i] - x[j])
            }
        }

        Y += y[i] * L;                                  // Add the weighted Lagrange basis polynomial to the interpolated value
    }

    cout << "For X = " << X << " , Y = " << Y << endl;  // Output the result of the interpolation
}

//----------------------------------------------------------------Main Program-------------------------------------------------------------------
int main(int argc, char **argv)
{
    double x[] = {5, 7, 11, 13};                        // Array of x values for interpolation
    double y[] = {150, 392, 1452, 2366};                // Array of corresponding y values
    int n = sizeof(x) / sizeof(x[0]);                   // Calculate the number of data points
    double X;                                           // Variable to hold user input for interpolation

    cout << "Enter value for x: ";                      // Prompt the user to enter a value for X
    cin >> X;                                           // Read the input value for X
    lagranges_interpolation(x, y, n, X);                // Call the Lagrange interpolation function and print the result

    return 0;
}