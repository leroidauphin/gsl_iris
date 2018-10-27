
#ifndef GSL_VARIABLES_H
#define GSL_VARIABLES_H

#include "initialiser.hpp"
#include "variables.hpp"

#include <gsl/gsl_vector.h>

#include <cstddef>
#include <memory>

/*
class GSLVariables : public Variables {
	public:
		static std::unique_ptr<GSLVariables> make_variables(size_t n_values, Initialiser& initialiser);

		gsl_vector get_values();
	private:
		const std::unique_ptr<gsl_vector> values;

		GSLVariables(gsl_vector* values): values(values)
		{}
};
*/

/*
template <>
class Variables<gsl_vector> {
	const std::unique_ptr<gsl_vector> values;

	public:
		Variables<gsl_vector>(const Variables<gsl_vector>& other): values(std::unique_ptr<gsl_vector>(other.values.get()))
		{}

		static std::unique_ptr<Variables<gsl_vector>> make_variables(size_t n_values, Initialiser& initialiser);

		gsl_vector get_values();
	protected:
		Variables<gsl_vector>(gsl_vector* values): values(values)
		{}
};


std::unique_ptr<Variables<gsl_vector>> Variables<gsl_vector>::make_variables(size_t n_values, Initialiser& initialiser) {
	auto vector(gsl_vector_alloc(n_values));
	for (size_t i = 0; i < n_values; i++){
		gsl_vector_set(vector, i, initialiser.get_value());
	}
	return std::unique_ptr<Variables<gsl_vector>>(new Variables<gsl_vector>(vector));
}

gsl_vector Variables<gsl_vector>::get_values() {
	return *values;
}
*/


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

