#ifndef GSL_TRAINING_H
#define GSL_TRAINING_H

#include "training.hpp"

#include <gsl/gsl_vector.h>


class GSLCost: public Cost<gsl_vector*> {
    gsl_vector* compute_cost(std::shared_ptr<Variables<gsl_vector*>> input);
};


#endif
