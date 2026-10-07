#pragma once
#include "Option.hpp"

class BlackScholesPricer {
	public:
		explicit BlackScholesPricer(const Option& option);
		double price() const;
		double delta() const;

	private:
		const Option& option_;

		double normalCDF(double value) const;
		double normalPDF(double value) const;
		void computeD1D2(double& d1, double& d2) const;
};
