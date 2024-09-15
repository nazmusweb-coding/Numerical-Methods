#----------------------------------------------Function Definitions--------------------------------------------
def f(x):
    return 0.1 * x**5 - 0.2 * x**3 + 0.1 * x - 0.2                                              # Define the function f(x)

def forward_differences(x, h):
    dff1 = (f(x + h) - f(x)) / h                                                                # Compute the first derivative using forward differences
    dff2 = (f(x + 2 * h) - 2 * f(x + h) + f(x)) / h**2                                          # Compute the second derivative
    dff3 = (f(x + 3 * h) - 3 * f(x + 2 * h) + 3 * f(x + h) - f(x)) / h**3                       # Compute the third derivative
    dff4 = (f(x + 4 * h) - 4 * f(x + 3 * h) + 6 * f(x + 2 * h) - 4 * f(x + h) + f(x)) / h**4    # Compute the fourth derivative

    print(f"f'({x}) = {dff1:.6f}\nf''({x}) = {dff2:.6f}\nf'''({x}) = {dff3:.6f}\nf''''({x}) = {dff4:.6f}")  # Print forward differences results

def central_differences(x, h):
    dfc1 = (f(x + h) - f(x - h)) / (2 * h)                                                      # Compute the first derivative using central differences
    dfc2 = (f(x + h) - 2 * f(x) + f(x - h)) / h**2                                              # Compute the second derivative
    dfc3 = (f(x + 2 * h) - 2 * f(x + h) + 2 * f(x - h) - f(x - 2 * h)) / h**3                   # Compute the third derivative
    dfc4 = (f(x + 2 * h) - 4 * f(x + h) + 6 * f(x) - 4 * f(x - h) + f(x - 2 * h)) / h**4        # Compute the fourth derivative

    print(f"f'({x}) = {dfc1:.6f}\nf''({x}) = {dfc2:.6f}\nf'''({x}) = {dfc3:.6f}\nf''''({x}) = {dfc4:.6f}")  # Print central differences results

def backward_differences(x, h):
    dfb1 = (f(x) - f(x - h)) / h                                                                # Compute the first derivative using backward differences
    dfb2 = (f(x) - 2 * f(x - h) + f(x - 2 * h)) / h**2                                          # Compute the second derivative
    dfb3 = (f(x) - 3 * f(x - h) + 3 * f(x - 2 * h) - f(x - 3 * h)) / h**3                       # Compute the third derivative
    dfb4 = (f(x) - 4 * f(x - h) + 6 * f(x - 2 * h) - 4 * f(x - 3 * h) + f(x - 4 * h)) / h**4    # Compute the fourth derivative

    print(f"f'({x}) = {dfb1:.6f}\nf''({x}) = {dfb2:.6f}\nf'''({x}) = {dfb3:.6f}\nf''''({x}) = {dfb4:.6f}")  # Print backward differences results

#--------------------------------------------------Main Program------------------------------------------------
def main():
    x, h = map(float, input("Enter value for x and h: ").split())  # Prompt user and read x and h

    print("Forward differences:")
    forward_differences(x, h)       # Compute and display forward differences 
    print("Central differences:")
    central_differences(x, h)       # Compute and display central differences
    print("Backward differences:")
    backward_differences(x, h)      # Compute and display backward differences


if __name__ == "__main__":
    main()
