from math import sin, pi                            # Import the sine function and the constant pi from the math module

#----------------------------------------------Function Definitions--------------------------------------------
def f(x):
    return x * sin(x)                               # Define the function f(x) = x * sin(x)

def trapezoidal_rule(lower_limit, upper_limit, number_of_divisions):
    a = lower_limit                                 # Set lower limit of integration
    b = upper_limit                                 # Set upper limit of integration
    n = number_of_divisions                         # Number of divisions for trapezoidal rule
    h = (b - a) / n                                 # Compute the width of each trapezoid
    S = 0.5 * (f(a) + f(b))                         # Initialize sum with the average of the function values at the ends
    for i in range(1, n):                           # Iterate through the divisions
        S += f(a + i * h)                           # Add the function value at each subdivision point
    Integral = h * S                                # Compute the integral as the width times the sum
    print(f"Integral = {Integral} [using trapezoidal rule]") # Output the result

def simpsons1_3rule(lower_limit, upper_limit, number_of_divisions):
    a = lower_limit                                 # Set lower limit of integration
    b = upper_limit                                 # Set upper limit of integration
    n = number_of_divisions                         # Number of divisions for Simpson's 1/3 rule
    h = (b - a) / n                                 # Compute the width of each interval
    S = f(a) + f(b)                                 # Initialize sum with the function values at the ends
    for i in range(1, n, 2):                        # Iterate over odd indices
        S += 4 * f(a + i * h)                       # Add 4 times the function value at each odd index
    for i in range(2, n, 2):                        # Iterate over even indices
        S += 2 * f(a + i * h)                       # Add 2 times the function value at each even index
    Integral = (h / 3) * S                          # Compute the integral using Simpson's 1/3 rule formula
    print(f"Integral = {Integral} [using simpson's 1/3 rule]") # Output the result

def simpsons3_8rule(lower_limit, upper_limit, number_of_divisions):
    a = lower_limit                                 # Set lower limit of integration
    b = upper_limit                                 # Set upper limit of integration
    n = number_of_divisions                         # Number of divisions for Simpson's 3/8 rule
    h = (b - a) / n                                 # Compute the width of each interval
    S = f(a) + f(b)                                 # Initialize sum with the function values at the ends
    for i in range(1, n, 3):                        # Iterate over indices with step 3
        S += 3 * (f(a + i * h) + f(a + (i + 1) * h))# Add 3 times the sum of function values at each set of 3 points
    for i in range(3, n, 3):                        # Iterate over indices with step 3 starting from 3
        S += 2 * f(a + i * h)                       # Add 2 times the function value at each subsequent set of 3 points
    Integral = ((3 * h) / 8) * S                    # Compute the integral using Simpson's 3/8 rule formula
    print(f"Integral = {Integral} [using simpson's 3/8 rule]") # Output the result

#--------------------------------------------------Main Program------------------------------------------------
def main():
    lower_limit = 0                                 # Set lower limit of integration
    upper_limit = pi / 2                            # Set upper limit of integration (π/2)
    trapezoidal_rule(lower_limit, upper_limit, 100) # Compute and print integral using trapezoidal rule with 100 divisions
    simpsons1_3rule(lower_limit, upper_limit, 18)   # Compute and print integral using Simpson's 1/3 rule with 18 divisions
    simpsons3_8rule(lower_limit, upper_limit, 18)   # Compute and print integral using Simpson's 3/8 rule with 18 divisions


if __name__ == "__main__":
    main()