
#ifndef LAYERS_H
#define LAYERS_H

#include "variables.hpp"


class Layer {
	public:
		virtual Variables apply(Variables input) = 0;
};


#endif

