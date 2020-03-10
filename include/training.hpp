
#ifndef TRAINING_H
#define TRAINING_H

#include <model.hpp>
#include "variables.hpp"


template<class T>
class Cost {
    public:
        virtual double compute_cost(
            std::shared_ptr<Variables<T>> predictions,
            std::shared_ptr<Variables<T>> targets
        );
};


#endif
