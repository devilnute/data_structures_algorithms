cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME DATA_STRUCTURES_ALGORITHMS)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
src/BinarySearchTree.h
src/DoublyLinkedList.h
src/DynamicArray.h
src/ForwardList.h
src/HashMap.h
src/HashSet.h
src/main.cpp
src/MyDeque.h
src/MyException.cpp
src/MyException.h
src/MyQueue.h
src/MyStack.h
src/Pair.h
src/PriorityQueue.h
src/RandomAccessIterator.h
src/RingBuffer.h
src/SearchAlgorithms.h
src/SortingAlgorithms.h
src/StaticArray.h
src/Timer.cpp
src/Timer.h
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
