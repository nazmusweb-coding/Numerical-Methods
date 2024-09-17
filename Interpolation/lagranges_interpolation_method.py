#------------------------------------------------------------Function Definitions-----------------------------------------------------------
def lagranges_interpolation(x, y, X):
    n = len(x)                                  # Get the number of data points
    Y = 0                                       # Initialize the interpolated value Y to 0

    for i in range(n):                          # Iterate over each data point to calculate the interpolation value
        L = 1                                   # Initialize the Lagrange basis polynomial L_i to 1 for the current i
        for j in range(n):                      # Calculate the Lagrange basis polynomial L_i(X)
            if j != i:
                L *= (X - x[j]) / (x[i] - x[j]) # Compute the product of (X - x[j]) / (x[i] - x[j])
        Y += y[i] * L                           # Add the weighted Lagrange basis polynomial to the interpolated value
    print(f"For x = {X}, y = {Y}")              # Print the result of the interpolation

#----------------------------------------------------------------Main Program---------------------------------------------------------------
def main():
    # Define data points for interpolation
    x = [5, 7, 11, 13]                          # List of x values (data points)
    y = [150, 392, 1452, 2366]                  # Corresponding y values (data points)

    X = float(input("Enter value for x: "))     # Prompt the user for an interpolation point 
    lagranges_interpolation(x, y, X)            # Perform Lagrange interpolation and print the result


if __name__ == "__main__":
    main()