
#include "initialiser.hpp"

#include <gsl/gsl_randist.h>

#include <memory>

std::unique_ptr<GaussianInitialiser> GaussianInitialiser::make_initialiser(){
	gsl_rng_env_setup();

	auto rng_type = gsl_rng_default;
	auto rng_generator = gsl_rng_alloc(rng_type);

	return std::unique_ptr<GaussianInitialiser>(new GaussianInitialiser(rng_generator));
}

GaussianInitialiser::~GaussianInitialiser(){
	gsl_rng_free(random.get());
}


double GaussianInitialiser::get_value(){ 
	return gsl_ran_gaussian(random.get(), 1.0);
}

