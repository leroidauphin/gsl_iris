
#include <layers.hpp>
#include <model.hpp>
#include <training.hpp>

#include <gtest/gtest.h>


TEST(test_trainer, test_train_model){
	std::list<std::shared_ptr<Layer<int>>> list;
    auto model = std::make_shared<Model<int>>(list);
    Trainer<int> trainer(model);

	trainer.train();
}

