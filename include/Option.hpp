#pragma once
class Option {
	public:
		enum class Type { Call, Put };
		Option(double spot, double strike, double timeToMaturity, double riskFreeRate, double volatility, Type type);

		double getSpot() const;
		double getStrike() const;
		double getTimeToMaturity() const;
		double getRiskFreeRate() const;
		double getVolatility() const;
		Type getType() const;

	private:
		double spot_;
		double strike_;
		double timeToMaturity_;
		double riskFreeRate_;
		double volatility_;
		Type type_;

};
