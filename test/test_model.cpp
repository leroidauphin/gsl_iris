
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

		void set_values(int value) {
			values = value;
		}

		Variables(int values): values(values)
		{}

		~Variables<int>() = default;
	private:
		int values;
};


class IntLayer: public Layer<int> {
	public:
		~IntLayer() = default;

		Variables<int> apply(Variables<int> input) {
			input.set_values(input.get_values() * layer);
			return input;
		}

		IntLayer(int layer): layer(layer)
		{}
	private:
		int layer;

};


TEST(test_model, test_no_layers){
	std::list<std::unique_ptr<Layer<int>>> list;
	Model<int> model;

	auto variables_initialiser = 2;
	auto int_variables = Variables<int>(variables_initialiser);

	auto output_variables = model.apply(int_variables);
	auto output_values = output_variables.get_values();

	ASSERT_EQ(output_values, 2.0);
}


TEST(test_model, test_one_layer){
	Model<int> model;
	auto one_layer = std::make_unique<IntLayer>(3);
	model.add_layer(std::move(one_layer));

	auto variables_initialiser = 2;
	auto input_variables = Variables<int>(variables_initialiser);

	auto output_variables = model.apply(input_variables);
	auto output_values = output_variables.get_values();

	ASSERT_EQ(output_values, 6.0);
}


TEST(test_model, test_two_layers){
	Model<int> model;
	auto one_layer = std::make_unique<IntLayer>(3);
	model.add_layer(std::move(one_layer));
	auto two_layer = std::make_unique<IntLayer>(5);
	model.add_layer(std::move(two_layer));

	auto variables_initialiser = 2;
	auto input_variables = Variables<int>(variables_initialiser);

	auto output_variables = model.apply(input_variables);
	auto output_values = output_variables.get_values();

	ASSERT_EQ(output_values, 30.0);
}


TEST(test_model, test_train_model){
	Model<int> model;

	model.train();
}
