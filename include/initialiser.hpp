
#ifndef INITIALISER_H
#define INITIALISER_H


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

#endif
