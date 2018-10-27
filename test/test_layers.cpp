
#include "utils.hpp"

#include "gsl_layers.hpp"
#include "gsl_variables.hpp"
#include "initialiser.hpp"
#include "layers.hpp"

#include "gtest/gtest.h"


TEST(constant_gsllayer_test, test_constant_gsllayer){
	auto initialiser = ConstantInitialiser(3.0);
	auto layer = GSLLayer::make_layer(1, 1, initialiser);

	auto variables_initialiser = ConstantInitialiser(2.0);
	auto variables = Variables<gsl_vector>::make_variables(1, variables_initialiser);

	auto output = layer->apply(*variables);
	auto output_values = output.get_values();
	auto values = gsl_vector_get(&output_values, 0);

	EXPECT_EQ(values, 0);
}
