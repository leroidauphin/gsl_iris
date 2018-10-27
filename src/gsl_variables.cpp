
#include "gsl_variables.hpp"

#include <gsl/gsl_vector.h>

#include <cstddef>
#include <memory>


std::unique_ptr<Variables<gsl_vector>> Variables<gsl_vector>::make_variables(size_t n_values, Initialiser& initialiser) {
	auto vector(gsl_vector_alloc(n_values));
	for (size_t i = 0; i < n_values; i++){
		gsl_vector_set(vector, i, initialiser.get_value());
	}
	return std::unique_ptr<Variables<gsl_vector>>(new Variables<gsl_vector>(vector));
}

Variables<gsl_vector>::~Variables() {
	gsl_vector_free(values.get());
}	

gsl_vector Variables<gsl_vector>::get_values() {
	return *values;
}

