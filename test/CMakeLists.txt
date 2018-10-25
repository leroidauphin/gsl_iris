add_library(TestLayers test_layers.cpp)

add_executable(run_unit_tests run_unit_tests.cpp)
target_link_libraries(run_unit_tests TestLayers)
target_link_libraries(run_unit_tests ${GTEST_BOTH_LIBRARIES})
target_link_libraries(run_unit_tests pthread)

add_test(AllUnitTests run_unit_tests)
