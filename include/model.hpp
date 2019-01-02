
#ifndef MODEL_H
#define MODEL_H

#include "layers.hpp"

#include <list>


template<class T>
class Model {
	public:
		Model(std::list<std::shared_ptr<Layer<T>>> layers): layers(layers)
		{}

		void apply(std::shared_ptr<Variables<T>> input);
	private:
		const std::list<std::shared_ptr<Layer<T>>> layers;
};


template<class T>
void Model<T>::apply(std::shared_ptr<Variables<T>> input) {
    for (const auto layer : layers) {
        layer->apply(input);
    }
}


#endif

