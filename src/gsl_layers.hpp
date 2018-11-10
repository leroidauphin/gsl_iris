
#ifndef GSL_LAYERS_H
#define GSL_LAYERS_H

#include "initialiser.hpp"
#include "layers.hpp"

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

#include <cstddef>
#include <memory>

class GSLLayer: public Layer<gsl_vector> {
	public:
		static std::unique_ptr<GSLLayer> make_layer(size_t n_nodes, size_t node_size, Initialiser& initialiser);

		~GSLLayer();

		Variables<gsl_vector> apply(Variables<gsl_vector> input);
	private:
		const std::unique_ptr<gsl_matrix> layer;
		const std::unique_ptr<gsl_vector> bias;

		GSLLayer(gsl_matrix* layer, gsl_vector* bias): layer(layer), bias(bias)
		{}
};


#endif

