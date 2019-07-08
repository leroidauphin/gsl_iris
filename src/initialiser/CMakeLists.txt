add_library(Initialisers gsl_initialiser.cpp)
target_compile_features(Initialisers PUBLIC cxx_std_17)
target_include_directories(Initialisers PUBLIC ${COMMON_INCLUDES})
