//
// Created by Tobias on 2019/1/27.
//


#include <iostream>
#include "Sorting/SortTestHelper.h"
#include "Sorting/SelectionSort.h"
#include "Sorting/InsertionSort.h"
#include "Sorting/MergeSort.h"
#include "Sorting/QuickSort.h"
#include "Sorting/HeapSort.h"

using namespace std;


int nomain2() {
    int n = 100000;
    int *test = SortTestHelper::generateRandomArray(n, 0, 10);
//    SortTestHelper::testSort("Insertion Sort",insertionSort,test,n);
//    SortTestHelper::testSort("Selection Sort",selectionSort,test,n);
//    SortTestHelper::testSort("Merge Sort", mergeSort, test, n);
//    SortTestHelper::testSort("MergeSelf Sort", mergeSelfSort, test, n);
//    SortTestHelper::testSort("Merge Sort BU", mergeSortBU, test, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, test, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, test, n);
    SortTestHelper::testSort("Quick Sort 3", quickSort3, test, n);
    SortTestHelper::testSort("Quick Sort 3_2", quickSort2, test, n);
    SortTestHelper::testSort("Quick Sort 3_2", quickSort2, test, n);
    SortTestHelper::testSort("Heap Sort",heapSort1,test,n);
    SortTestHelper::testSort("Heap Sort 2",heapSort2,test,n);
    SortTestHelper::testSort("Heap Sort 3",heapSort3,test,n);
    delete[] test;
//    int *t = SortTestHelper::generateRandomArray(10, 0, 10);
//    SortTestHelper::printArray(t, 10);
//    heapSort2(t, 10);
//    SortTestHelper::printArray(t, 10);
//    delete[] t;
    return 0;
}