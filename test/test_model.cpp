
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

		void apply(std::shared_ptr<Variables<int>> input) {
			input->set_values(input->get_values() * layer);
		}

		IntLayer(int layer): layer(layer)
		{}
	private:
		int layer;

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
	auto one_layer = std::make_shared<IntLayer>(3);
	std::list<std::shared_ptr<Layer<int>>> list{one_layer};
	Model<int> model(list);

	auto variables_initialiser = 2;
	auto variable_ptr = std::make_shared<Variables<int>>(variables_initialiser);

	model.apply(variable_ptr);
	auto output_values = variable_ptr->get_values();

	ASSERT_EQ(output_values, 6.0);
}


TEST(test_model, test_two_layers){
	auto one_layer = std::make_shared<IntLayer>(3);
	auto two_layer = std::make_shared<IntLayer>(5);
	std::list<std::shared_ptr<Layer<int>>> list{one_layer, two_layer};
	Model<int> model(list);

	auto variables_initialiser = 2;
	auto variable_ptr = std::make_shared<Variables<int>>(variables_initialiser);

	model.apply(variable_ptr);
	auto output_values = variable_ptr->get_values();

	ASSERT_EQ(output_values, 30.0);
}


TEST(test_model, test_train_model){
	std::list<std::shared_ptr<Layer<int>>> list;
    Model<int> model(list);

	model.train();
}
