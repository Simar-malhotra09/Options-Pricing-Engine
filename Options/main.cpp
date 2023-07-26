#include <iostream>
#include "GenericOption.h"
#include "GenericOption.cpp"

int main()
{
    GenericOption option(100.0, OptionType_Put, 1.1);
    double price1 = 120.0;
    double value = option.valueAtExpiration(price1);
    std::cout << "For 100PUT, value at expiration for price " << price1 << " is " << value << std::endl;

    double price2 = 85.0;
    value = option.valueAtExpiration(price2);
    std::cout << "For 100PUT, value at expiration for price " << price2 << " is " << value << std::endl;

    // Test profitAtExpiration
    double limit = 120.0;
    for (double price = 80.0; price <= limit; price += 0.1) {
        value = option.profitAtExpiration(price);
        std::cout << price << ", " << value << std::endl;
    }

    return 0;
}
