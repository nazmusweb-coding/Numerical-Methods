#-----------------------------------Function Declaration----------------------------------
def f(X):
    return 2*X**2 - 5*X + 3                 # Define the function f(X) = 2*X^2 - 5*X + 3

def f1(X):
    return 4*X - 5                          # Define the derivative of f(X), f'(X) = 4*X - 5

def newton_raphson_method(X):
    iteration = 1                           # Initialize the iteration counter
    while True:
        print(f"{iteration} {X:0.5f}")      # Print the current iteration number and X value
        Xnew = X - f(X)/f1(X)               # Compute the new value of X using the Newton-Raphson update formula
        if abs(X - Xnew) < 1e-6:            # Check if the difference between the current and new X is smaller than the tolerance
            break                           # Exit the loop if the difference is within the tolerance
        X = Xnew                            # Else Update X with the new value
        iteration += 1                      # And Increment the iteration counter

    print(f"Root found at iteration {iteration}, root is {X:0.5f}")  # Print the final result with 5 decimal places

#-----------------------------------Main Program-------------------------------------------
def main():
    X = float(input("Enter value for X: ")) # Prompt the user for the initial value of X
    newton_raphson_method(X)                # Call the Newton-Raphson method with the user-provided initial value


if __name__ == "__main__":
    main()