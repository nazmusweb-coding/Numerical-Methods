import numpy as np                                              # Import numpy to use zeros for 2D array

#------------------------------------------------------------Function Definitions-----------------------------------------------------------
def newtons_method(x, y, X):
    n = len(x) - 1                                              # Determine the number of data points minus one
    Dy = np.zeros((n + 1, n + 1))                               # Initialize a (n+1)x(n+1) matrix to store divided differences
    Dy[:, 0] = y                                                # Set the first column of Dy to the y values (0th divided differences)
    
    for i in range(n):                                          # Loop through each order of divided differences
        for j in range(i + 1, n + 1):                           # Loop through the rows to compute each divided difference
            Dy[j, i + 1] = (Dy[j, i] - Dy[i, i]) / (x[j] - x[i])# Calculate divided difference for the current entry

    Y = Dy[0, 0]                                                # Initialize Y with the 0th divided difference (constant term)
    
    for i in range(n):                                          # Loop through each term in the Newton polynomial
        xprod = 1                                               # Initialize the product term for the current polynomial term
        for j in range(i + 1):                                  # Compute the product (X - x0)(X - x1)...(X - x_i)
            xprod *= X - x[j]
        Y += xprod * Dy[i + 1, i + 1]                           # Add the weighted term to the final result

    print(f"For x = {X}, y = {Y}")                              # Print the result of the interpolation

#----------------------------------------------------------------Main Program---------------------------------------------------------------
def main():
    x = [1891, 1901, 1911, 1921, 1931]                          # Define x values (data points)
    y = [46, 66, 81, 93, 101]                                   # Define corresponding y values (data points)
    
    X = float(input("Enter value for x: "))                     # Prompt the user for a value of x to interpolate
    newtons_method(x, y, X)                                     # Call Newton's method function to compute and print the interpolated value


if __name__ == "__main__":       
    main()