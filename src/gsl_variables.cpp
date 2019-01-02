
#include "gsl_variables.hpp"

#include <gsl/gsl_vector.h>

#include <cstddef>
#include <memory>


std::shared_ptr<Variables<gsl_vector*>> Variables<gsl_vector*>::make_variables(size_t n_values, Initialiser& initialiser) {
	auto vector(gsl_vector_alloc(n_values));
	for (size_t i = 0; i < n_values; i++){
		gsl_vector_set(vector, i, initialiser.get_value());
	}
	auto variables = new Variables<gsl_vector*>(vector);
	std::shared_ptr<Variables<gsl_vector*>> ptr = std::shared_ptr<Variables<gsl_vector*>>(variables);
	return ptr;
}


gsl_vector * Variables<gsl_vector*>::get_values() {
	return values;
}
