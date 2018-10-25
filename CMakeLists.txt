cmake_minimum_required(VERSION 3.12)

option(TEST "All tests." OFF)

set(PROJECT_NAME IrisClassification)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

find_package(GSL REQUIRED)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

if (TEST)
	enable_testing()
	find_package(GTest REQUIRED)

	add_subdirectory(${PROJECT_SOURCE_DIR}/test)
endif (TEST)

