
#ifndef GSL_VARIABLES_H
#define GSL_VARIABLES_H

#include "initialiser.hpp"
#include "variables.hpp"

#include <gsl/gsl_vector.h>

#include <cstddef>
#include <memory>

template <>
class Variables<gsl_vector> {
	const std::unique_ptr<gsl_vector> values;

	public:
		Variables<gsl_vector>(const Variables<gsl_vector>& other): values(std::unique_ptr<gsl_vector>(other.values.get()))
		{}
		~Variables<gsl_vector>();

		static std::unique_ptr<Variables<gsl_vector>> make_variables(size_t n_values, Initialiser& initialiser);

		gsl_vector get_values();
	protected:
		Variables<gsl_vector>(gsl_vector* values): values(values)
		{}
};


#endif

