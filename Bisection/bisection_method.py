#-----------------------------------Function Declaration----------------------------------
def f(x):
    return 2 * x**2 - 5 * x + 3                                     # Define the function f(x) = 2*x^2 - 5*x + 3

def bisection_method(a, b):
    if f(a) * f(b) >= 0:                                            # Check if f(a) and f(b) have the same sign
        print("No roots exist within given interval")               # Print a message indicating that the interval is not valid
        exit(0)                                                     # Exit the program as the bisection method cannot proceed
    iteration = 1                                                   # Initialize the iteration counter   

    while True:
        c = (a + b) / 2                                             # Compute the midpoint c of the interval [a, b]
        print(f"{iteration} {c:0.5f}")                              # Print the current iteration number and midpoint c value
        
        if abs(f(c)) < 1e-6:                                        # Check if the function value at c is within the tolerance
            print(f"Root found at iteration {iteration}, root is {c:0.5f}")  # Print the final result
            break                                                   # Exit the loop if the root is found
        elif f(a) * f(c) < 0:                                       # Check if the root is in the interval [a, c]
            b = c                                                   # Update b to c if the root is in [a, c]
        else:
            a = c                                                   # Update a to c if the root is in [c, b]
        iteration += 1                                              # Increment the iteration counter

#-----------------------------------Main Program-------------------------------------------
def main():
    a, b = map(float, input("Enter value for a and b: ").split())   # Prompt user for values of a and b and convert them to float
    bisection_method(a, b)                                          # Call the bisection method with the provided values


if __name__ == "__main__":
    main()