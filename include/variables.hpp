
#ifndef VARIABLES_H
#define VARIABLES_H

#include <memory>

template <class T>
class Variables {
	public:
		virtual ~Variables() = default;

		T get_values();
};



#endif
