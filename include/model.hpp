
#ifndef MODEL_H
#define MODEL_H

#include "layers.hpp"

#include <list>


template<class T>
class Model {
	public:
		Model<T> () {};

		void add_layer(std::unique_ptr<Layer<T>> layer);

		Variables<T> apply(Variables<T> input);

		void train();
	private:
		std::list<std::unique_ptr<Layer<T>>> layers;
};


template<class T>
void Model<T>::add_layer(std::unique_ptr<Layer<T>> layer) {
	layers.push_back(std::move(layer));
}


template<class T>
Variables<T> Model<T>::apply(Variables<T> input) {
	Variables<T> output = input;
    for (auto&& layer: layers) {
        output = layer->apply(output);
    }

	return output;
}


template<class T>
void Model<T>::train() {
	
}


#endif

