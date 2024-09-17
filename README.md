# Numerical Methods Repository

Welcome to the Numerical Methods repository! This project includes implementations of various numerical methods in both C++ and Python. The Python implementations are designed to mimic C++ conventions to help C++ coders transition smoothly to Python.

## Methods Implemented

### 1. Simple Iteration / Brute Force Method
A basic iterative approach for solving equations.

### 2. Newton-Raphson Method
A numerical technique for finding successively better approximations to the roots of a real-valued function.

### 3. Bisection Method
A root-finding method that repeatedly bisects an interval and then selects a subinterval in which a root must lie for further processing.

### 4. Numerical Differentiation
   - **Forward Finite Differences:** Approximates the derivative of a function using forward differences.
   - **Central Finite Differences:** Approximates the derivative using central differences.
   - **Backward Finite Differences:** Approximates the derivative using backward differences.

### 5. Numerical Integration
   - **Trapezoidal Rule:** Approximates the integral of a function using trapezoids.
   - **Simpson's 1/3 Rule:** Approximates the integral of a function using parabolic segments.
   - **Simpson's 3/8 Rule:** A variation of Simpson's rule using cubic polynomials.
   - **Simpson's 1/3 Double Integration Rule:** Extends Simpson's 1/3 rule to double integrals.

### 6. Interpolation
   - **Linear Interpolation:** Estimates unknown values by assuming a linear relationship between known values.
   - **Lagrange's Interpolation:** Provides a polynomial interpolation through a set of data points.
   - **Newton's Method:** Provides an interpolating polynomial in Newton form.

## Installation

To use the C++ and Python implementations, you'll need to have the appropriate compilers or interpreters installed:

### C++:
- Install a C++ compiler (e.g., `g++` or `clang++`).

### Python:
- Ensure you have Python 3.x installed. You can download it from [python.org](https://www.python.org/).

## Usage

### C++

To compile and run the C++ code, navigate to the C++ source directory and use the following commands:

```bash
g++ -o method_name method_name.cpp
./method_name
```

##### Alternative Approache:
You can use an [online compiler](https://www.programiz.com/cpp-programming/online-compiler/) such as Programiz to compile and run your C++ code directly in the browser.

### Python

To run the Python code, navigate to the Python source directory and use the following command:

```bash
python method_name.py
```

##### Alternative Approaches:
- Google Colab: Use [Google Colab](https://colab.research.google.com/notebooks/intro.ipynb#scrollTo=5Y9LXc69ndOO) to run your Python code in a cloud-based environment.

- JupyterLite: Try [JupyterLite](https://jupyterlite.github.io/demo/lab/index.html) (to try without login) for an online Jupyter notebook experience without needing to log in.

These platforms provide suitable environments for Python and are generally better than other online interpreters available.