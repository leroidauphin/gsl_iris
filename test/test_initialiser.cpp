
#include "initialiser.hpp"

#include "gtest/gtest.h"


TEST(sample_initialiser, test_gaussian_initialiser) {
	auto initialiser = GaussianInitialiser::make_initialiser();
	auto value = initialiser->get_value();

	EXPECT_DOUBLE_EQ(value, 0.1339186081186759);
}
