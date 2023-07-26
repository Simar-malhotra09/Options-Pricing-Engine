#include <iostream>
#include "CRRBionomialModel.h"

int main() {
    double S = 100.0;
    double K = 110.0;
    double T = 2.221918;
    double r = 0.05;
    double sigma = 0.30;
    int N = 1000;
    char Option_type = 'C';

    // Create an instance of CRRBinomial with member variables
    CRRBinomial binomialOption(S, K, T, r, sigma, N, Option_type);

    // Calculate the option price using the member function
    double optionPrice = binomialOption.calculateOptionPrice();

    std::cout << "Option Price: " << optionPrice << std::endl;

    return 0;
}

/*
Underlying price	S	100.000000
Strike price	K	110.000000
Time to maturity	T	2.221918
Risk-free interest rate	r	5.000000
Volatility	sigma	30.000000

Output:
Option Price: 18.351
*/