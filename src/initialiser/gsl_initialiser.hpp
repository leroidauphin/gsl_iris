#ifndef GSL_INITIALISER_H
#define GSL_INITIALISER_H

#include "initialiser.hpp"

#include <gsl/gsl_rng.h>

#include <memory>

class GaussianInitialiser: public Initialiser {
	const std::unique_ptr<gsl_rng> random;
	
	public:
		static std::unique_ptr<GaussianInitialiser> make_initialiser();

		~GaussianInitialiser();

		double get_value();
	protected:
		GaussianInitialiser(gsl_rng* random): random(random)
		{}
};


#endif
