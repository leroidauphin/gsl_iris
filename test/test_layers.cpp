
#include "gsl_layers.hpp"
#include "initialiser.hpp"
#include "layers.hpp"

#include "gtest/gtest.h"


class ConstantInitialiser : public Initialiser {
	public:
		ConstantInitialiser()
		{}

		double get_value() {
			return 1.0;
		}
};


TEST(constant_gsllayer_test, test_constant_gsllayer){
	auto initialiser = ConstantInitialiser();
	auto layer = GSLLayer::make_layer(1, 1, initialiser);
	EXPECT_EQ(1, 0);
}
