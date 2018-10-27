

#include "gsl_layers.hpp"

std::unique_ptr<GSLLayer> GSLLayer::make_layer(size_t n_nodes, size_t node_size, Initialiser& initialiser){
	auto matrix(gsl_matrix_alloc(n_nodes, node_size));
	for (size_t i = 0; i < n_nodes; i++){
		for (size_t j = 0; j < node_size; j++) {
			gsl_matrix_set(matrix, i, j, initialiser.get_value());
		}
	}
	return std::unique_ptr<GSLLayer>(new GSLLayer(matrix));
}

Variables<gsl_vector> GSLLayer::apply(Variables<gsl_vector> input) {
	return input;
}

