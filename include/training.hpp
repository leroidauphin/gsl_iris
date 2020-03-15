
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
        ) = 0;
};


template<class T>
class BatchCost {
    public:
        virtual double compute_cost(
            std::list<std::shared_ptr<Variables<T>>> predictions,
            std::list<std::shared_ptr<Variables<T>>> targets
	) = 0;
};


template<class T>
class MeanBatchCost : public BatchCost<T> {
    public:
	MeanBatchCost(Cost<T> single_cost): single_cost(single_cost)
	{} 
        double compute_cost(
            std::list<std::shared_ptr<Variables<T>>> predictions,
            std::list<std::shared_ptr<Variables<T>>> targets
	){
		auto predictions_iter = predictions.begin();
		auto targets_iter = targets.begin();

		for(;
		    predictions_iter != predictions.end() &&
		    targets_iter != targets.end();
		    ++predictions_iter, ++targets_iter) {
			auto prediction = predictions_iter->get_values();
		}
		return 0;
	}
    private:
	Cost<T> single_cost;
};

#endif
