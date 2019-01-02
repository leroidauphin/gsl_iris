
#include "utils.hpp"

#include <model.hpp>

#include <gtest/gtest.h>
#include <list>


template <>
class Variables<int> {

	public:
		Variables(const Variables<int>&) = default;

		int get_values() {
			return values;
		}

		Variables(int values): values(values)
		{}

		~Variables<int>() = default;
	private:
		int values;
};



TEST(test_model, test_no_layers){
	std::list<std::shared_ptr<Layer<int>>> list;
	Model<int> model(list);

	auto variables_initialiser = 2;
	auto variable_ptr = std::make_shared<Variables<int>>(variables_initialiser);

	model.apply(variable_ptr);
	auto output_values = variable_ptr->get_values();

	ASSERT_EQ(output_values, 2.0);
}


TEST(test_model, test_one_layer){
}


TEST(test_mode, test_two_layers){
}
