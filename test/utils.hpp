
#ifndef UTILS_H
#define UTILS_H

#include "initialiser.hpp"


class ConstantInitialiser : public Initialiser {
	const double value;

	public:
		ConstantInitialiser(double value): value(value)
		{}

		double get_value() {
			return value;
		}
};


#endif
