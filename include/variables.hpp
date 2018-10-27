
#ifndef VARIABLES_H
#define VARIABLES_H

#include <gsl/gsl_vector.h>
#include <memory>

template <class T>
class Variables {
	const std::unique_ptr<T> values;

	public:
		Variables(const Variables& other): values(std::unique_ptr<T>(other.values.get()))
		{}

		T get_values();

	protected:
		Variables(T* values): values(values)
		{}
};



#endif
