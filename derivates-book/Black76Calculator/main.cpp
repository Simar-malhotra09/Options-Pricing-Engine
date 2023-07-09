#include "Black76Calc.h"
#include <iostream>

int main() {
    Black76 black76;

    double underlyingPrice = 100.0;
    double strikePrice = 95.0;
    double timeToMaturity = 0.5;
    double volatility = 0.2;
    double marketPrice = 8.0;

    try {
        auto values = black76.getValues(Black76::CALL, underlyingPrice, strikePrice, timeToMaturity, volatility);
        std::cout << "Option Value: " << std::get<0>(values) << std::endl;
        std::cout << "Delta: " << std::get<1>(values) << std::endl;
        std::cout << "Gamma: " << std::get<2>(values) << std::endl;
        std::cout << "Vega: " << std::get<3>(values) << std::endl;
        std::cout << "Theta: " << std::get<4>(values) << std::endl;
        std::cout << "Rho: " << std::get<5>(values) << std::endl;

        double impliedVolatility = black76.getImpliedVolatility(Black76::CALL, underlyingPrice, strikePrice, timeToMaturity, marketPrice);
        std::cout << "Implied Volatility: " << impliedVolatility << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
