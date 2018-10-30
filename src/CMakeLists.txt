add_library(GSLLayers gsl_layers.cpp gsl_layers.hpp gsl_variables.cpp gsl_variables.hpp)
target_compile_features(GSLLayers PUBLIC cxx_std_17)
target_include_directories(GSLLayers PUBLIC ${COMMON_INCLUDES})
target_include_directories(GSLLayers PUBLIC ${GSL_INCLUDE_DIRS})
target_link_libraries(GSLLayers ${GSL_LIBRARIES})

add_subdirectory(initialiser)
