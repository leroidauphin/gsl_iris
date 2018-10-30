
#ifndef INITIALISER_H
#define INITIALISER_H

#include <gsl/gsl_rng.h>

#include <memory>


class Initialiser {
	public:
		Initialiser() = default;
		Initialiser(const Initialiser&) = default;
		Initialiser(Initialiser&&) = default;
		Initialiser& operator=(const Initialiser&) = default;
		Initialiser& operator=(Initialiser&&) = default;
		virtual ~Initialiser() = default;

		virtual double get_value() = 0;
};


class GaussianInitialiser: public Initialiser {
	const std::unique_ptr<gsl_rng> random;
	
	public:
		static std::unique_ptr<GaussianInitialiser> make_initialiser();

		~GaussianInitialiser();

		double get_value();
	protected:
		GaussianInitialiser(gsl_rng* random): random(random)
		{}
};


#endif
