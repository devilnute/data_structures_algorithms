cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME DATA_STRUCTURES_ALGORITHMS)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
src/main.cpp
src/Timer.h
src/Timer.cpp
src/Iterator.h
src/SearchAlgorithms.h
src/SortingAlgorithms.h
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
