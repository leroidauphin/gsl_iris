
#include "layers.hpp"

#include "gtest/gtest.h"


class ConstantInitialiser : public Initialiser {
	public:
		ConstantInitialiser()
		{}

		float get_value();
};


float ConstantInitialiser::get_value() {
	return 1.0;
}


TEST(constant_layer_test, test_constant_layer){
	auto initialiser = ConstantInitialiser();
	Layer layer = Layer::make_layer(1, 1, initialiser);
	EXPECT_EQ(1, 0);
}
