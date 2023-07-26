#ifndef BLACK76CALC_H
#define BLACK76CALC_H

#include <iostream>
#include <tuple>

class Black76 {
public:
    static const char CALL;
    static const char PUT;

    static const int METHOD_BISECTION;
    static const int METHOD_NEWTON_RAPHSON;

    Black76(double interestRate = 0.01);

    std::tuple<double, double, double, double, double, double> getValues(char type, double underlyingPrice, double strikePrice, double timeToMaturity, double volatility);

    double getImpliedVolatility(char type, double underlyingPrice, double strikePrice, double timeToMaturity, double marketPrice, int method = METHOD_BISECTION);

private:
    double interestRate;

    std::pair<double, double> d1d2(double underlyingPrice, double strikePrice, double timeToMaturity, double volatility);

    double impliedVolaUsingBisection(char type, double underlyingPrice, double strikePrice, double timeToMaturity, double marketPrice);

    double cdf(double x);

    double pdf(double x);
};

#endif
