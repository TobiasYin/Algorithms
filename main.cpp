//
// Created by Tobias on 2019/1/27.
//


#include <iostream>
#include "Sorting/SortTestHelper.h"
#include "Sorting/SelectionSort.h"
#include "Sorting/InsertionSort.h"
#include "Sorting/MergeSort.h"
#include "Sorting/QuickSort.h"

using namespace std;


int main() {
    int n = 500000;
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
    delete[] test;
//    int *t = SortTestHelper::generateRandomArray(10, 0, 10);
//    SortTestHelper::printArray(t, 10);
//    quickSort3_2(t, 10);
//    SortTestHelper::printArray(t, 10);
    return 0;
}