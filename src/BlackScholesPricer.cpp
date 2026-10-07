#include "BlackScholesPricer.hpp"
#include <cmath>

BlackScholesPricer::BlackScholesPricer(const Option& option) : option_(option) {}

double BlackScholesPricer::normalCDF(double value) const {
    return 0.5 * std::erfc(-value * M_SQRT1_2);
}

double BlackScholesPricer::normalPDF(double value) const {
    return (1.0 / std::sqrt(2.0 * M_PI)) * std::exp(-0.5 * value * value);
}

void BlackScholesPricer::computeD1D2(double& d1, double& d2) const {
    double S = option_.getSpot();
    double K = option_.getStrike();
    double T = option_.getTimeToMaturity();
    double r = option_.getRiskFreeRate();
    double v = option_.getVolatility();

    d1 = (std::log(S / K) + (r + 0.5 * v * v) * T) / (v * std::sqrt(T));
    d2 = d1 - v * std::sqrt(T);
}

double BlackScholesPricer::price() const {
    double d1, d2;
    computeD1D2(d1, d2);

    double S = option_.getSpot();
    double K = option_.getStrike();
    double T = option_.getTimeToMaturity();
    double r = option_.getRiskFreeRate();

    if (option_.getType() == Option::Type::Call) {
        return S * normalCDF(d1) - K * std::exp(-r * T) * normalCDF(d2);
    } else {
        return K * std::exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
    }
}

double BlackScholesPricer::delta() const {
    double d1, d2;
    computeD1D2(d1, d2);

    if (option_.getType() == Option::Type::Call) {
        return normalCDF(d1);
    } else {
        return normalCDF(d1) - 1.0;
    }
}

