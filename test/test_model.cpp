
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
	private:
		int values;
};



TEST(test_model, test_no_layers){
	std::list<std::shared_ptr<Layer<int>>> list;
	Model<int> model(list);

	std::cout << "Model construction" << std::endl;

	auto variables_initialiser = 2;
	auto variables = Variables<int>(variables_initialiser);

	std::cout << "Variables construction" << std::endl;

	auto output = model.apply(variables);
	auto output_values = output.get_values();

	std::cout << "Output Values" << std::endl;

	ASSERT_EQ(output_values, 2.0);
}


TEST(test_model, test_one_layer){
}


TEST(test_mode, test_two_layers){
}
