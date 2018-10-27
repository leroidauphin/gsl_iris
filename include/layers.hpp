
#ifndef LAYERS_H
#define LAYERS_H

#include "variables.hpp"


template<class T>
class Layer {
	public:
		virtual Variables<T> apply(Variables<T> input) = 0;
};


#endif

