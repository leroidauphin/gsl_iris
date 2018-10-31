
#include "initialiser.hpp"

#include "gtest/gtest.h"


TEST(sample_initialiser, test_gaussian_initialiser) {
	auto initialiser = GaussianInitialiser::make_initialiser();
	auto value = initialiser->get_value();

	std::cout << value << std::endl;

	EXPECT_DOUBLE_EQ(value, 0.133919);  // segfaults?

	std::cout << value << std::endl;
}
