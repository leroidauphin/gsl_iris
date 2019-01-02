

#include "gsl_layers.hpp"

#include "gsl/gsl_blas.h"
#include <iostream>

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
	gsl_matrix_free(layer);
}


void GSLLayer::apply(std::shared_ptr<Variables<gsl_vector*>> input) {
	auto input_size = input->get_values()->size;
	auto target_vector = gsl_vector_alloc(input_size);
	auto input_values = input->get_values();
	gsl_blas_dgemv(CblasNoTrans, 1.0, layer, input_values, 0.0, target_vector);

	for (size_t i = 0; i < input_size; i++) {
		auto value = gsl_vector_get(target_vector, i);
		gsl_vector_set(input_values, i, value);
	}
}

