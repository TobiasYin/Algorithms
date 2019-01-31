//
// Created by Tobias on 2019/1/27.
//

#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

#include <iostream>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T now = arr[i];
        int j = i;
        for (; j > 0 && arr[j - 1] > now; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = now;
    }
}

template<typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        T now = arr[i];
        int j = i;
        for (; j > l && arr[j - 1] > now; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = now;
    }
}


#endif //ALGORITHMS_INSERTIONSORT_H
