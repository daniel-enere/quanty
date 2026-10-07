#include <iostream>
#include <cmath>
#include <cassert>
#include "Option.hpp"
#include "BlackScholesPricer.hpp"

void testBlackScholesCall() {
    // Standard ATM Call: S=100, K=100, T=1.0, r=0.05, v=0.20
    Option opt(100.0, 100.0, 1.0, 0.05, 0.20, Option::Type::Call);
    BlackScholesPricer pricer(opt);

    double price = pricer.price();
    double delta = pricer.delta();

    std::cout << "Testing BS Call... Price: " << price << ", Delta: " << delta << "\n";
    
    // Benchmark expected values (within 0.001 tolerance)
    assert(std::abs(price - 10.4506) < 0.001);
    assert(std::abs(delta - 0.6368) < 0.001);
}

void testBlackScholesPut() {
    // Standard ATM Put: S=100, K=100, T=1.0, r=0.05, v=0.20
    Option opt(100.0, 100.0, 1.0, 0.05, 0.20, Option::Type::Put);
    BlackScholesPricer pricer(opt);

    double price = pricer.price();
    double delta = pricer.delta();

    std::cout << "Testing BS Put... Price: " << price << ", Delta: " << delta << "\n";
    
    // Benchmark expected values
    assert(std::abs(price - 5.5735) < 0.001);
    assert(std::abs(delta - (-0.3631)) < 0.001);
}

int main() {
    try {
        testBlackScholesCall();
        testBlackScholesPut();
        std::cout << "ALL QUANT ENGINE TESTS PASSED!\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << "\n";
        return 1;
    }
}

