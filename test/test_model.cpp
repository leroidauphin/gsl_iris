
#include <model.hpp>

#include <gtest/gtest.h>
#include <list>


TEST(test_model, test_no_layers){
	std::list<std::shared_ptr<Layer<int>>> list;
	Model<int> model(list);

}


TEST(test_model, test_one_layer){
}


TEST(test_mode, test_two_layers){
}
