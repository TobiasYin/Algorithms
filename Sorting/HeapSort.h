//
// Created by Tobias on 2019/2/1.
//

#ifndef ALGORITHMS_HEAPSORT_H
#define ALGORITHMS_HEAPSORT_H

#include<iostream>
#include "MaxHeap.h"

using namespace std;

template<typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> heap = MaxHeap<T>(n);
    for (int i = 0; i < n; ++i) {
        heap.add(arr[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        arr[i] = heap.get();
    }
}

template<typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> heap = MaxHeap<T>(arr, n);
    for (int i = n - 1; i >= 0; --i) {
        arr[i] = heap.get();
    }
}

template<typename T>
void shiftDown(T data[], int n, int count) {
    while (2 * n + 1 < count) {
        int j = 2 * n + 1;
        if (j + 1 < count && data[j + 1] > data[j]) {
            j++;
        }
        if (data[n] < data[j]) {
            swap(data[n], data[j]);
            n = j;
        } else break;
    }
}

template<typename T>
void heapSort3(T arr[], int n) {
    for (int i = (n - 1) / 2; i >= 0; --i) {
        shiftDown(arr, i, n);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        shiftDown(arr, 0, i);
    }
}


#endif //ALGORITHMS_HEAPSORT_H
