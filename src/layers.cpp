

#include "layers.hpp"

Layer Layer::make_layer(size_t n_nodes, size_t node_size, Initialiser& initialiser){
	auto matrix(gsl_matrix_alloc(n_nodes, node_size));
	return Layer(matrix);
}



