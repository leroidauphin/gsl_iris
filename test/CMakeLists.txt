add_executable(run_test_layers test_layers.cpp)
target_include_directories(run_test_layers PUBLIC ${COMMON_INCLUDES})
target_link_libraries(run_test_layers Layers)
target_link_libraries(run_test_layers ${GTEST_BOTH_LIBRARIES})
target_link_libraries(run_test_layers pthread)

add_test(NAME TestLayersUnitTests COMMAND run_test_layers)

