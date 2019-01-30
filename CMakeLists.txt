cmake_minimum_required(VERSION 3.13)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithms Sorting/SelectionSort.h Sorting/SortTestHelper.h main.cpp Sorting/InsertionSort.h Sorting/MergeSort.h)