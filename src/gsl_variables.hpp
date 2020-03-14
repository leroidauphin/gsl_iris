
#ifndef GSL_VARIABLES_H
#define GSL_VARIABLES_H

#include "initialiser.hpp"
#include "variables.hpp"

#include <gsl/gsl_vector.h>

#include <cstddef>
#include <memory>

class GSLVariables: public Variables<gsl_vector*> {

	public:
		static GSLVariables make_variables(size_t n_values, Initialiser& initialiser);

		gsl_vector * get_values();

		GSLVariables(gsl_vector* values): values(values)
		{}
	private:
		gsl_vector* values;
};


#endif

