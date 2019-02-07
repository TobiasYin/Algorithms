cmake_minimum_required(VERSION 3.13)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithms Sorting/SelectionSort.h Sorting/SortTestHelper.h SortTestMain.cpp Sorting/InsertionSort.h Sorting/MergeSort.h Sorting/IndexHeap.h Sorting/QuickSort.h Sorting/MaxHeap.h HeapTestMain.cpp Sorting/HeapSort.h Search/BinarySearch.h Search/BinarySearchTree.h UnionFInd.h GraphTheory/SparseGraph.h GraphTheory/DenseGraph.h main.cpp GraphTheory/ReadGraph.h GraphTheory/Component.h GraphTheory/Path.h GraphTheory/ShortestPath.h)