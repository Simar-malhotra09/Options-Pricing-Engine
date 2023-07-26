## Black-Scholes Option Pricing with Bisection Method

This C++ code implements the Black-Scholes (Black76) option pricing model using the Bisection Method to calculate implied volatility. The Black76 model is used to price European-style options on futures contracts, and it assumes a constant interest rate.

### How to Use

1. **Prerequisites:** Ensure you have a C++ compiler and the necessary libraries installed. This code uses the `cmath`, `utility`, `iostream`, and `stdexcept` standard libraries.

2. **Compile:** Compile the code using your C++ compiler. For example, using `g++`:

```
g++ main.cpp Black76Calc.cpp -o option_pricing
```

3. **Run:** Execute the compiled binary to run the program and calculate option prices and implied volatility. The `main.cpp` file provides an example usage of the `Black76` class.

### Overview of Files

1. `Black76Calc.h` and `Black76Calc.cpp`: These files contain the implementation of the `Black76` class, which handles the option pricing calculations and implied volatility using the Bisection Method.

2. `main.cpp`: This is the main C++ file that demonstrates how to use the `Black76` class to calculate option prices and implied volatility for call and put options.

3. `README.md`: This file provides an overview of the code and instructions for running the program.

### How the Code Works

1. The `Black76` class contains methods to calculate the d1 and d2 values, option Greeks (delta, gamma, vega, theta, and rho), and implied volatility using the Bisection Method.

2. The `impliedVolaUsingBisection()` method implements the Bisection Method to find the implied volatility for a given option market price.

3. The `getImpliedVolatility()` method provides a wrapper to choose between the Bisection Method and the Newton-Raphson method for implied volatility calculation (only Bisection Method is currently implemented).

4. The `cdf()` and `pdf()` functions are utility functions to calculate the cumulative distribution function (CDF) and probability density function (PDF) of the standard normal distribution, respectively.

### Note

This code is for educational purposes and does not account for all real-world factors that may affect option pricing. Use it responsibly and validate the results against other reliable sources.

Feel free to modify and improve the code as needed to suit your specific requirements.
