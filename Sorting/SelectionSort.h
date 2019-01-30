//
// Created by Tobias on 2019/1/27.
//
#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H


#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

#endif //ALGORITHMS_SELECTIONSORT_H