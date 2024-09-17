#------------------------------------------------------------Function Definitions-----------------------------------------------------------
def linear_interpolation(x, y, X):
    x1 = x2 = y1 = y2 = None                            # Initialize variables to store the x and y values for interpolation
    length = len(x)                                     # Get the length of the x list

    for i in range(length):
        if x[i] > X:                                    # Check if the current x value is greater than X
            x1 = x[i - 1]                               # Set x1 to the value before the current x
            x2 = x[i]                                   # Set x2 to the current x value
            y1 = y[i - 1]                               # Set y1 to the y value corresponding to x1
            y2 = y[i]                                   # Set y2 to the y value corresponding to x2
            break                                       # Exit the loop as the interval has been found
    
    Y = y1 + ((y2 - y1) / (x2 - x1)) * (X - x1)         # Calculate the interpolated value Y using the formula for linear interpolation
    print(f"For X = {X}, Y = {Y}")                      # Print the result of the interpolation

#----------------------------------------------------------------Main Program---------------------------------------------------------------
def main():
    # Time (seconds) and Temperature (Celsius) Table
    x = [0, 20, 40, 60, 80, 100]                        # List of time values
    y = [26.0, 48.6, 61.6, 71.2, 74.8, 75.2]            # List of corresponding temperature values

    # Time (seconds) and Distance (meters) Table
    x_1 = [0, 10, 15, 20, 22.5, 30]                     # List of time values for a different case
    y_1 = [0, 227.04, 362.73, 517.35, 602.97, 901.67]   # List of corresponding distance values
    
    # Prompt user for interpolation value for the first case (Temperature)
    X = float(input("Case 1: Enter value for x(Time and Temperature): "))
    linear_interpolation(x, y, X)                       # Perform linear interpolation for temperature case
    
    # Prompt user for interpolation value for the second case (Distance)
    X = float(input("Case 2: Enter value for x(Time and Distance): "))
    linear_interpolation(x_1, y_1, X)                   # Perform linear interpolation for distance case


if __name__ == "__main__":
    main()