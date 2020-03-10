#include "gsl_training.hpp"

#include "gsl/gsl_sf_log.h"


double GSLCrossEntropyCost::compute_cost(
    std::shared_ptr<Variables<gsl_vector*>> predictions,
    std::shared_ptr<Variables<gsl_vector*>> targets
) {
    auto prediction_values = predictions->get_values();
    auto target_values = targets->get_values();

    double accumulator = 0.0;

    for (size_t i = 0; i < target_values->size; i++) {
        auto prediction_value = gsl_vector_get(prediction_values, i);
		auto target_value = gsl_vector_get(target_values, i);

        accumulator += gsl_sf_log(prediction_value) * target_value;
        accumulator += gsl_sf_log(1 - prediction_value) * (1 - target_value);
	}

    return accumulator;
}
