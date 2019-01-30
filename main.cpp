//
// Created by Tobias on 2019/1/27.
//


#include <iostream>
#include "Sorting/SortTestHelper.h"
#include "Sorting/SelectionSort.h"
#include "Sorting/InsertionSort.h"
#include "Sorting/MergeSort.h"

using namespace std;


int main(){
    int n = 500000;
    int* test = SortTestHelper::generateRandomArray(n,0,n);
//    SortTestHelper::testSort("Insertion Sort",insertionSort,test,n);
//    delete[] test;
//    test = SortTestHelper::generateRandomArray(n,0,n);
//    SortTestHelper::testSort("Selection Sort",selectionSort,test,n);
//    delete[] test;
//    test = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::testSort("Merge Sort",mergeSort,test,n);
    delete[] test;
    test = SortTestHelper::generateRandomArray(n,0,n);
//    SortTestHelper::testSort("MergeSelf Sort",mergeSelfSort,test,n);
//    delete[] test;
//    test = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::testSort("Merge Sort BU",mergeSortBU,test,n);
    delete[] test;
    //    int* t = SortTestHelper::generateRandomArray(100,0,100);
//    mergeSortBU(t,100);
//    SortTestHelper::printArray(t,100);
    return 0;
}