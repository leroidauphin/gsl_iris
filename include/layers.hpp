
#ifndef LAYERS_H
#define LAYERS_H

#include <gsl/gsl_matrix.h>

#include <cstddef>
#include <memory>


class Initialiser {
	public:
		Initialiser(const Initialiser&) = default;
		Initialiser(Initialiser&&) = default;
		Initialiser& operator=(const Initialiser&) = default;
		Initialiser& operator=(Initialiser&&) = default;
		virtual ~Initialiser() = default;
};


class GaussianInitialiser: public Initialiser {
};


class Layer {

	public:
		static Layer make_layer(size_t n_nodes, size_t node_size, Initialiser& initialiser);
	private:
		const std::unique_ptr<gsl_matrix> layer;

		Layer(gsl_matrix* layer): layer(layer)
		{}
};


#endif

