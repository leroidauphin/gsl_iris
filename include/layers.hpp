
#ifndef LAYERS_H
#define LAYERS_H

#include "variables.hpp"


template<class T>
class Layer {
	public:
		virtual void apply(std::shared_ptr<Variables<T>> input) = 0;
};


#endif

