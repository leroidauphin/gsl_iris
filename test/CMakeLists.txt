add_executable(run_test_layers test_initialiser.cpp test_layers.cpp test_model.cpp test_training.cpp test_variables.cpp utils.hpp)
target_include_directories(run_test_layers PUBLIC ${COMMON_INCLUDES})
target_include_directories(run_test_layers PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(run_test_layers PUBLIC ${PROJECT_SOURCE_DIR}/src/initialiser)
target_link_libraries(run_test_layers Initialisers)
target_link_libraries(run_test_layers GSLLayers)
target_link_libraries(run_test_layers ${GTEST_BOTH_LIBRARIES})
target_link_libraries(run_test_layers pthread)

gtest_discover_tests(run_test_layers)

