
#ifndef GSL_VARIABLES_H
#define GSL_VARIABLES_H

#include "initialiser.hpp"
#include "variables.hpp"

#include <gsl/gsl_vector.h>

#include <cstddef>
#include <memory>

template <>
class Variables<gsl_vector*> {

	public:
		static Variables<gsl_vector*> make_variables(
			size_t n_values, Initialiser& initialiser
		){
			auto vector(gsl_vector_alloc(n_values));
			for (size_t i = 0; i < n_values; i++){
				gsl_vector_set(vector, i, initialiser.get_value());
			}
			auto variables = Variables<gsl_vector*>(vector);
			return variables;
		}

		gsl_vector * get_values() {
			return values;
		}

		Variables(gsl_vector* values): values(values)
		{}
	private:
		gsl_vector* values;
};


#endif

