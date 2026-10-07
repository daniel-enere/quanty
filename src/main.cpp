#include <iostream>
#include <string>
#include <cstdlib>
#include "Option.hpp"
#include "BlackScholesPricer.hpp"

void printUsage(const char* progName) {
    std::cout << "Usage: " << progName << " <spot> <strike> <time> <rate> <vol> <call|put>\n"
              << "Example: " << progName << " 100.0 100.0 1.0 0.05 0.20 call\n";
}

int main(int argc, char* argv[]) {
    if (argc != 7) {
        printUsage(argv[0]);
        return 1;
    }

    double spot = std::stod(argv[1]);
    double strike = std::stod(argv[2]);
    double time = std::stod(argv[3]);
    double rate = std::stod(argv[4]);
    double vol = std::stod(argv[5]);
    std::string typeStr = argv[6];

    Option::Type type;
    if (typeStr == "call") {
        type = Option::Type::Call;
    } else if (typeStr == "put") {
        type = Option::Type::Put;
    } else {
        std::cerr << "Error: Option type must be either 'call' or 'put'.\n";
        return 1;
    }

    Option option(spot, strike, time, rate, vol, type);
    BlackScholesPricer pricer(option);

    std::cout << "=== Black-Scholes Pricing Engine ===" << "\n";
    std::cout << "Spot Price:    " << spot << "\n";
    std::cout << "Strike Price:  " << strike << "\n";
    std::cout << "Maturity (Yrs):" << time << "\n";
    std::cout << "Risk-Free Rate:" << rate << "\n";
    std::cout << "Volatility:    " << vol << "\n";
    std::cout << "Option Type:   " << typeStr << "\n";
    std::cout << "------------------------------------" << "\n";
    std::cout << "Option Price:  " << pricer.price() << "\n";
    std::cout << "Delta:         " << pricer.delta() << "\n";

    return 0;
}

