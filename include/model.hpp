
#ifndef MODEL_H
#define MODEL_H

#include "layers.hpp"

#include <list>


template<class T>
class Model {
	public:
		Model(std::list<std::shared_ptr<Layer<T>>> layers): layers(layers)
		{}

		Variables<T> apply(Variables<T> input) {
			return input;
		}
	private:
		const std::list<std::shared_ptr<Layer<T>>> layers;
};


#endif

