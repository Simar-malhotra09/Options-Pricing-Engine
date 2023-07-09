#include <cmath>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include "Black76Calc.h"
using namespace std;


const char Black76::CALL = 'C';
const char Black76::PUT = 'P';

const int Black76::METHOD_BISECTION = 1;
const int Black76::METHOD_NEWTON_RAPHSON = 2;

Black76::Black76(double interestRate) : interestRate(interestRate) {}

std::pair<double, double> Black76::d1d2(double underlyingPrice, double strikePrice, double timeToMaturity, double volatility) {
    double d1 = (log(underlyingPrice / strikePrice) + (pow(volatility, 2) / 2) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
    double d2 = d1 - volatility * sqrt(timeToMaturity);

    return std::make_pair(d1, d2);
}

tuple<double, double, double, double, double, double > Black76::getValues(char type, double underlyingPrice, double strikePrice, double timeToMaturity, double volatility) {
    double discountFactor = exp(-interestRate * timeToMaturity);

    std::pair<double, double> d1d2Values = d1d2(underlyingPrice, strikePrice, timeToMaturity, volatility);
    double d1 = d1d2Values.first;
    double d2 = d1d2Values.second;

    double sign = (type == CALL) ? 1 : -1;

    double nd1 = cdf(d1 * sign);
    double nd2 = cdf(d2 * sign);
    double normpdf = pdf(d1);
    double sqrtTimeToMaturity = sqrt(timeToMaturity);

    double value = sign * discountFactor * (underlyingPrice * nd1 - strikePrice * nd2);

    double delta = sign * discountFactor * nd1;
    double gamma = discountFactor * normpdf / (volatility * underlyingPrice * sqrtTimeToMaturity);
    double vega = 0.01 * underlyingPrice * discountFactor * normpdf * sqrtTimeToMaturity;
    double theta = (-underlyingPrice * discountFactor * normpdf * volatility / (2 * sqrtTimeToMaturity)) +
        sign * interestRate * discountFactor * (underlyingPrice * nd1 - strikePrice * nd2);
    double rho = -0.01 * timeToMaturity * value;
    
    tuple greeks = make_tuple(value, delta, gamma, vega, theta, rho);

    return greeks;
}

double Black76::impliedVolaUsingBisection(char type, double underlyingPrice, double strikePrice, double timeToMaturity, double marketPrice) {
    double epsilon = 0.0001;
    int i = 0;
    int maxIterations = 100;

    double volMin = 0.00001;
    double volMax = 5;
    double volGuess = 0.0;

    do {
        
        tuple<double, double, double, double, double, double> valuesMin = getValues(type, underlyingPrice, strikePrice, timeToMaturity, volMin);
        tuple<double, double, double, double, double, double> valuesMax = getValues(type, underlyingPrice, strikePrice, timeToMaturity, volMax);

        double valueMin = std::get<0>(valuesMin);
        double valueMax = std::get<0>(valuesMax);
 

        volGuess = volMin + (marketPrice - valueMin) * (volMax - volMin) / (valueMax - valueMin);
        double valueGuess =std::get<0> (getValues(type, underlyingPrice, strikePrice, timeToMaturity, volGuess));

        if (valueGuess < marketPrice) {
            volMin = volGuess;
        } else {
            volMax = volGuess;
        }
    } while (++i <= maxIterations && volMax - volMin > epsilon);

    return volGuess;
}

double Black76::getImpliedVolatility(char type, double underlyingPrice, double strikePrice, double timeToMaturity, double marketPrice, int method) {
    switch (method) {
        case METHOD_BISECTION:
            return impliedVolaUsingBisection(type, underlyingPrice, strikePrice, timeToMaturity, marketPrice);
        case METHOD_NEWTON_RAPHSON:
            throw std::runtime_error("Not implemented");
        default:
            throw std::runtime_error("Wrong method " + std::to_string(method) + " or not supported");
    }
}

double Black76::cdf(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double Black76::pdf(double x) {
    return exp(-pow(x, 2) / 2) / sqrt(2 * M_PI);
}
