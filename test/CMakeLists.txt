add_executable(run_test_layers test_layers.cpp)
target_include_directories(run_test_layers PUBLIC ${COMMON_INCLUDES})
target_include_directories(run_test_layers PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(run_test_layers GSLLayers)
target_link_libraries(run_test_layers ${GTEST_BOTH_LIBRARIES})
target_link_libraries(run_test_layers pthread)

gtest_discover_tests(run_test_layers)

