#include "Option.hpp"

Option::Option(double spot, double strike, double timeToMaturity, double riskFreeRate, double volatility, Type type)
	: spot_(spot), strike_(strike), timeToMaturity_(timeToMaturity), riskFreeRate_(riskFreeRate), volatility_(volatility), type_(type) {}

	double Option::getSpot() const {return spot_; }
	double Option::getStrike() const { return strike_; }
	double Option::getTimeToMaturity() const { return timeToMaturity_; }
	double Option::getRiskFreeRate() const { return riskFreeRate_; }
	double Option::getVolatility() const { return volatility_; }
	Option::Type Option::getType() const { return type_; }
