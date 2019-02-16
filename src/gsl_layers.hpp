
#ifndef GSL_LAYERS_H
#define GSL_LAYERS_H

#include "initialiser.hpp"
#include "layers.hpp"

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

#include <cstddef>
#include <functional>
#include <memory>

class GSLLayer: public Layer<gsl_vector*> {
	public:
		static std::unique_ptr<GSLLayer> make_layer(size_t n_nodes, size_t node_size, Initialiser& initialiser, std::function<double(double)> activation_fn);

		~GSLLayer();

		void apply(std::shared_ptr<Variables<gsl_vector*>> input);
	private:
		gsl_matrix* layer;
		gsl_vector* bias;
		std::function<double(double)> activation_fn;

		GSLLayer(gsl_matrix* layer, gsl_vector* bias, std::function<double(double)> activation): layer(layer), bias(bias), activation_fn(activation)
		{}
};


#endif

