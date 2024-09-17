#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//------------------------------------------------------------Function Definitions-----------------------------------------------------------
void linear_interpolation(double x[], double y[], int n, double X)
{
    double x1, x2, y1, y2;                              // Variables to store the coordinates of the points for interpolation

    for (int i = 0; i < n; i++)                         // Loop through the data points to find the interval in which X falls
    {
        if (x[i] > X)                                   // Check if the current x value is greater than X
        {
            x1 = x[i - 1];                              // Set x1 to the value before the current x
            x2 = x[i];                                  // Set x2 to the current x value
            y1 = y[i - 1];                              // Set y1 to the y value corresponding to x1
            y2 = y[i];                                  // Set y2 to the y value corresponding to x2
            break;                                      // Exit the loop as the interval has been found
        }
    }

    double Y = y1 + ((y2 - y1) / (x2 - x1)) * (X - x1); // Calculate the interpolated value Y using the linear interpolation formula

    cout << "For X = " << X << " , Y = " << Y << endl;  // Output the result of the interpolation
}

//----------------------------------------------------------------Main Program-------------------------------------------------------------------
int main(int argc, char **argv)
{
    double x[] = {0, 20, 40, 60, 80, 100};              // Array of x values for interpolation
    double y[] = {26.0, 48.6, 61.6, 71.2, 74.8, 75.2};  // Array of corresponding y values
    int n = sizeof(x) / sizeof(x[0]);                   // Calculate the number of data points
    double X;                                           // Variable to hold user input for interpolation

    cout << "Enter value for x: ";                      // Prompt the user to enter a value for X
    cin >> X;                                           // Read the input value for X
    linear_interpolation(x, y, n, X);                   // Call the linear interpolation function and print the result

    return 0;
}