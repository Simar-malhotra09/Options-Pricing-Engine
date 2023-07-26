#ifndef CRRBionomialModel_H
#define CRRBionomialModel_H

#include <cmath>

class CRRBinomial {
private:
    double S;     // Underlying price (per share)
    double K;     // Strike price of the option (per share)
    double T;     // Time to maturity (years)
    double r;     // Continuously compounding risk-free interest rate
    double sigma; // Volatility
    int N;        // Number of binomial steps
    char Option_type; // Option type (e.g., 'C' for call, 'P' for put)

public:
    CRRBinomial(double S, double K, double T, double r, double sigma, int N, char Option_type);
    double calculateOptionPrice();
};

#endif
