
#include "gsl_variables.hpp"

#include <gsl/gsl_vector.h>

#include <cstddef>
#include <memory>


GSLVariables GSLVariables::make_variables(size_t n_values, Initialiser& initialiser) {
	auto vector(gsl_vector_alloc(n_values));
	for (size_t i = 0; i < n_values; i++){
		gsl_vector_set(vector, i, initialiser.get_value());
	}
	auto variables = GSLVariables(vector);
	return variables;
}


gsl_vector * GSLVariables::get_values() {
	return values;
}
