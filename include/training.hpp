
#ifndef TRAINING_H
#define TRAINING_H

#include <model.hpp>
#include "variables.hpp"


template<class T>
class Cost {
    public:
        virtual T compute_cost(std::shared_ptr<Variables<T>> input);
};


template<class T>
class Trainer {
    public:
        Trainer(std::shared_ptr<Model<T>> model): model(model)
        {}

        virtual void train();

	private:
		const std::shared_ptr<Model<T>> model;
};


template<class T>
void Trainer<T>::train() {

}


#endif
