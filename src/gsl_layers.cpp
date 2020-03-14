

#include "gsl_layers.hpp"
#include "gsl_variables.hpp"

#include "gsl/gsl_blas.h"
#include "gsl/gsl_vector.h"

#include <iostream>

Layer<gsl_vector*> Layer<gsl_vector*>::make_layer(
	size_t n_nodes, 
	size_t node_size, 
	Initialiser& initialiser, 
	std::function<double(double)> activation_fn
	){
	auto matrix(gsl_matrix_alloc(n_nodes, node_size));
	for (size_t i = 0; i < n_nodes; i++){
		for (size_t j = 0; j < node_size; j++) {
			gsl_matrix_set(matrix, i, j, initialiser.get_value());
		}
	}
	auto vector(gsl_vector_calloc(n_nodes));
	auto gsl_layer = Layer<gsl_vector*>(matrix, vector, activation_fn);
	return gsl_layer;
}


Layer<gsl_vector*>::~Layer<gsl_vector*>() {
	gsl_matrix_free(layer);
	gsl_vector_free(bias);
}


Variables<gsl_vector*> Layer<gsl_vector*>::apply(Variables<gsl_vector*> input) {
	auto input_values = input.get_values();
	size_t n_nodes = input_values->size;
	auto target_vector(gsl_vector_alloc(n_nodes));
	
	gsl_blas_dgemv(CblasNoTrans, 1.0, layer, input_values, 0.0, target_vector);
	gsl_blas_daxpy(1.0, bias, target_vector);

	for (size_t i = 0; i < target_vector->size; i++){
		auto value = gsl_vector_get(target_vector, i);
		auto activation_value = activation_fn(value);
		gsl_vector_set(target_vector, i, activation_value);
	}

	gsl_vector_free(input_values);

	auto output_values = Variables<gsl_vector*>(target_vector);

	return output_values;
}
