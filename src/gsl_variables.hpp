
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
		Variables(const Variables<gsl_vector*>&) = default;
		~Variables<gsl_vector*>();

		static std::shared_ptr<Variables<gsl_vector*>> make_variables(size_t n_values, Initialiser& initialiser);

		gsl_vector * get_values();

		Variables(gsl_vector* values): values(values)
		{}
	private:
		gsl_vector* values;
};


#endif

