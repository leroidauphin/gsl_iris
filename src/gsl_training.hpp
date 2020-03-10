#ifndef GSL_TRAINING_H
#define GSL_TRAINING_H

#include "training.hpp"

#include <gsl/gsl_vector.h>


class GSLCrossEntropyCost: public Cost<gsl_vector*> {
    double compute_cost(
        std::shared_ptr<Variables<gsl_vector*>> predictions,
        std::shared_ptr<Variables<gsl_vector*>> targets);
};


#endif
