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
        for (int j = i; j > 0; --j) {
            if (arr[j - 1] > now)
                arr[j] = arr[j - 1];
            else {
                arr[j] = now;
                break;
            }
        }
    }
}

template<typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        T now = arr[i];
        for (int j = i; j > l; --j) {
            if (arr[j - 1] > now)
                arr[j] = arr[j - 1];
            else {
                arr[j] = now;
                break;
            }
        }
    }
}


#endif //ALGORITHMS_INSERTIONSORT_H
