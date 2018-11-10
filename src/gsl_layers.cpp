

#include "gsl_layers.hpp"

#include "gsl/gsl_blas.h"

std::unique_ptr<GSLLayer> GSLLayer::make_layer(size_t n_nodes, size_t node_size, Initialiser& initialiser){
	auto matrix(gsl_matrix_alloc(n_nodes, node_size));
	for (size_t i = 0; i < n_nodes; i++){
		for (size_t j = 0; j < node_size; j++) {
			gsl_matrix_set(matrix, i, j, initialiser.get_value());
		}
	}
	auto vector(gsl_vector_calloc(n_nodes));
	return std::unique_ptr<GSLLayer>(new GSLLayer(matrix, vector));
}


GSLLayer::~GSLLayer() {
	gsl_matrix_free(layer.get());
}


Variables<gsl_vector> GSLLayer::apply(Variables<gsl_vector> input) {
	auto target_vector = gsl_vector_alloc(input.get_values().size);
	auto input_values = input.get_values();
	gsl_blas_dgemv(CblasNoTrans, 1.0, layer.get(), &input_values, 0.0, target_vector);
	return Variables<gsl_vector>(target_vector);
}

