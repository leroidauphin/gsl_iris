add_library(Layers layers.cpp layers.hpp)
target_compile_features(Layers PUBLIC cxx_std_17)
target_include_directories(Layers PUBLIC ${GSL_INCLUDE_DIRS})
