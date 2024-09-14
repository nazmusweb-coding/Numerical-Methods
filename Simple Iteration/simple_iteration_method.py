#-----------------------------------Function Declaration----------------------------------
def simple_interation_method(X):
    iteration = 1                               # Initialize the iteration counter 
    while True:
        print(f"{iteration} {X:.16f}")          # Print the current iteration number and X value
        Xnew = (2*X**2 + 3)/5                   # Compute the new value of X
        if X == Xnew:                           # Check if X and Xnew are the same
            break                               # Exit the loop if they are the same
        X = Xnew                                # Update X with the new value
        iteration += 1                          # Increment the iteration counter

    print(f"Root found at iteration {iteration}, root is {X:.16f}")  # Print the final result

#-----------------------------------Main Program-------------------------------------------
def main():
    X = float(input("Enter value for X: "))    # Prompt user for the initial value of X
    simple_interation_method(X)


if __name__ == "__main__":
    main()