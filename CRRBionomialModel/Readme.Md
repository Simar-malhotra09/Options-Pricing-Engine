## Cox-Ross-Rubinstein (CRR) Binomial Option Pricing Model

This C++ code implements the Cox-Ross-Rubinstein (CRR) Binomial option pricing model. The CRR model is a discrete-time option pricing model that can be used to value European-style options.

### How to Use

1. **Prerequisites:** Ensure you have a C++ compiler installed.

2. **Compile:** Compile the code using your C++ compiler. For example, using `g++`:

```
g++ main.cpp CRRBionomialModel.cpp -o option_pricing
```

3. **Run:** Execute the compiled binary to run the program and calculate option prices using the CRR Binomial model. The `main.cpp` file provides an example usage of the `CRRBinomial` class.

### Overview of Files

1. `CRRBionomialModel.h` and `CRRBionomialModel.cpp`: These files contain the implementation of the `CRRBinomial` class, which handles the CRR option pricing calculations.

2. `main.cpp`: This is the main C++ file that demonstrates how to use the `CRRBinomial` class to calculate option prices for call and put options.

### How the Code Works

1. The `CRRBinomial` class is initialized with the necessary parameters for option pricing, including the underlying price (S), strike price (K), time to maturity (T), risk-free interest rate (r), volatility (sigma), number of binomial steps (N), and the type of option (call or put).

2. The `calculateOptionPrice()` method implements the CRR Binomial model to calculate the option price based on the provided parameters.

3. The model works by creating a binomial tree of possible future prices of the underlying asset, from which the option price is derived by backward induction.

### Note

This code is for educational purposes and may not include all real-world factors that affect option pricing. It is intended to demonstrate the basic concepts of the CRR Binomial model. Always validate your results against reliable option pricing models and real-world data.

Feel free to modify and improve the code as needed to suit your specific requirements.
