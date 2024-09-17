#include <iostream>
#include <cstring>

using std::cout;
using std::cin;  
using std::endl; 

//------------------------------------------------------------Function Definitions-----------------------------------------------------------
void newton_method(double x[], double y[], int n, double X)
{
    double Dy[n + 1][n + 1];                                        // Create a 2D array to store divided differences of size (n+1) x (n+1)
    memset(Dy, 0, sizeof(Dy));                                      // Initialize the array with zeros using memset

    for (int i = 0; i < n; i++)                                     // Set the first column of Dy to the y values (0th divided differences)
    {
        Dy[i][0] = y[i];                                            // Assign y values to the first column of Dy
    }

    for (int i = 0; i < n; i++)                                     // Compute the divided differences and store them in Dy
    {
        for (int j = i + 1; j <= n; j++)
        {
            Dy[j][i + 1] = (Dy[j][i] - Dy[i][i]) / (x[j] - x[i]);   // Calculate the divided difference for Dy[j][i+1]
        }
    }

    double Y = Dy[0][0];                                            // Initialize Y with the 0th divided difference (constant term)

    for (int i = 0; i < n; i++)                                     // Evaluate the Newton polynomial at X
    {
        double xprod = 1;                                           // Initialize the product term for the current polynomial term
        for (int j = 0; j < i + 1; j++)
        {
            xprod *= X - x[j];                                      // Compute the product (X - x0)(X - x1)...(X - x_i)
        }
        Y += xprod * Dy[i + 1][i + 1];                              // Add the weighted term to the final result
    }

    cout << "For x = " << X << " , y = " << Y << endl;              // Output the result of the interpolation
}

//----------------------------------------------------------------Main Program-------------------------------------------------------------------
int main(int argc, char **argv)
{
    double x[] = {1891, 1901, 1911, 1921, 1931};                    // Array of x values for interpolation
    double y[] = {46, 66, 81, 93, 101};                             // Array of corresponding y values
    int n = sizeof(x) / sizeof(x[0]);                               // Calculate the number of data points
    double X;                                                       // Variable to hold user input for interpolation

    cout << "Enter value for x: ";                                  // Prompt the user to enter a value for X
    cin >> X;                                                       // Read the input value for X
    newton_method(x, y, n, X);                                      // Call the Newton interpolation function and print the result

    return 0;
}