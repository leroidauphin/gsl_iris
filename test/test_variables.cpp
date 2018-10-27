
#include "utils.hpp"

#include "gsl_variables.hpp"
#include "initialiser.hpp"

#include "gtest/gtest.h"

TEST(constant_gslvariables_test, test_constant_gslvariables){
	auto initialiser = ConstantInitialiser(2.0);
	auto variables = Variables<gsl_vector>::make_variables(1, initialiser);
	auto variable_values = variables->get_values();
	auto values = gsl_vector_get(&variable_values, 0);
	EXPECT_EQ(values, 2.0);
}


