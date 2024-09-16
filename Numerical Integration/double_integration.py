#------------------------------------------------------------------Function Definitions----------------------------------------------------------
def f(x, y):
    return x**2 * y + x * y**2                      # Define the function f(x, y) = x^2 * y + x * y^2 for double integration

def simpsons1_3double_integration_rule(lower_limit_x, upper_limit_x, lower_limit_y, upper_limit_y, number_of_divisions_x, number_of_divisions_y):
    ax = lower_limit_x                              # Set lower limit for x
    bx = upper_limit_x                              # Set upper limit for x
    ay = lower_limit_y                              # Set lower limit for y
    by = upper_limit_y                              # Set upper limit for y
    nx = number_of_divisions_x                      # Number of divisions for x
    ny = number_of_divisions_y                      # Number of divisions for y
    hx = (bx - ax) / nx                             # Compute the width of each interval for x
    hy = (by - ay) / ny                             # Compute the width of each interval for y
    S = 0                                           # Initialize the sum to zero
    for i in range(0, ny + 1):                      # Iterate over y intervals
        if i == 0 or i == ny:                       # For the first and last row
            p = 1                                   # Coefficient for boundary points
        elif i % 2 == 1:                            # For odd-indexed rows
            p = 4                                   # Coefficient for odd-indexed rows
        else:                                       # For even-indexed rows
            p = 2                                   # Coefficient for even-indexed rows
        for j in range(0, nx + 1):                  # Iterate over x intervals
            if j == 0 or j == nx:                   # For the first and last column
                q = 1                               # Coefficient for boundary points
            elif j % 2 == 1:                        # For odd-indexed columns
                q = 4                               # Coefficient for odd-indexed columns
            else:                                   # For even-indexed columns
                q = 2                               # Coefficient for even-indexed columns
            S += p * q * f(ax + j * hx, ay + i * hy)# Add weighted function value to the sum
    Integral = ((hx * hy) / 9) * S                  # Compute the integral using Simpson's 1/3 double integration formula
    print(f"Integral = {Integral} [using simpson's 1/3 double integration rule]") # Output the result

#----------------------------------------------------------------------Main Program--------------------------------------------------------------
def main():
    lower_limit_x = 1                               # Set lower limit for x
    upper_limit_x = 2                               # Set upper limit for x
    lower_limit_y = -1                              # Set lower limit for y
    upper_limit_y = 1                               # Set upper limit for y
    simpsons1_3double_integration_rule(lower_limit_x, upper_limit_x, lower_limit_y, upper_limit_y, 10, 10) # Compute and print integral


if __name__ == "__main__":
    main()
