//
// Created by Tobias on 2019/1/30.
//

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H

#include <iostream>

using namespace std;

template<typename T>
void mergeSelfSort(T arr[], int n) {
    if (n <= 1)
        return;

    int l = n / 2;
    int r = n - l;
    T arr1[l], arr2[r];
    for (int i = 0; i < l; ++i) {
        arr1[i] = arr[i];
    }
    for (int j = l; j < n; ++j) {
        arr2[j - l] = arr[j];
    }
    mergeSelfSort(arr1, l);
    mergeSelfSort(arr2, r);
    int i, j, k;
    i = j = k = 0;
    while (i < l || j < r) {
        if (i < l && j < r) {
            if (arr1[i] < arr2[j]) arr[k++] = arr1[i++];
            else arr[k++] = arr2[j++];
        } else if (i < l) arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }
}

template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T temp[r - l + 1];
    for (int i = l; i <= r; ++i) {
        temp[i - l] = arr[i];
    }
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = temp[j++ - l];
        } else if (j > r) {
            arr[k] = temp[i++ - l];
        } else if (temp[i - l] > temp[j - l]) {
            arr[k] = temp[j++ - l];
        } else {
            arr[k] = temp[i++ - l];
        }
    }
}

template<typename T>
void __mergeSort(T arr[], int l, int r) {
//    if (l >= r)
//        return;
    if (r - l < 15) {
        insertionSort(arr, l, r);
        return;
    }
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    if (arr[mid] < arr[mid + 1])
        return;
    __merge(arr, l, mid, r);
}


template<typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}

template<typename T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz <= n; sz *= 2) {
        for (int i = 0; i + sz < n; i += (2 * sz)) {
            if (arr[i + sz - 1] >= arr[i + sz])
                __merge(arr, i, i + sz - 1, min(n - 1, i + 2 * sz - 1));
        }
    }
}

#endif //ALGORITHMS_MERGESORT_H
