//
// Created by Tobias on 2019/1/31.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include <iostream>

using namespace std;

template<typename T>
void __quickSort(T arr[], int l, int r) {
//    if (r - l <= 15) {
//        insertionSort(arr, l, r);
//        return;
//    }
    if (l >= r)
        return;
    swap(arr[rand() % (r - l + 1) + l], arr[l]);
    int j = l;
    for (int i = l + 1; i <= r; i++)
        if (arr[i] < arr[l])
            swap(arr[++j], arr[i]);
    swap(arr[j], arr[l]);
    __quickSort(arr, l, j - 1);
    __quickSort(arr, j + 1, r);
}

template<typename T>
void __quickSort2(T arr[], int l, int r) {
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
    swap(arr[rand() % (r - l + 1) + l], arr[l]);
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < arr[l]) i++;
        while (j >= l + 1 && arr[j] > arr[l]) j--;
        if (i >= j) break;
        swap(arr[i++], arr[j--]);
    }
    swap(arr[j], arr[l]);
    __quickSort2(arr, l, j - 1);
    __quickSort2(arr, j + 1, r);
}

template<typename T>
void __quickSort3(T arr[], int l, int r) {
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
    swap(arr[rand() % (r - l + 1) + l], arr[l]);
    int p = r;
    int i;
    int x = 0;
    for (i = l + 1; i <= p - x; ++i) {
        if (arr[i] > arr[l]) {
            swap(arr[i--], arr[p--]);
            if (x > 0) swap(arr[i + 1], arr[p - x + 1]);
        } else if (arr[i] == arr[l]) {
            swap(arr[p - x++], arr[i--]);
        }
    }
    swap(arr[l], arr[i - 1]);
    __quickSort3(arr, l, i - 2);
    __quickSort3(arr, p + 1, r);
}

template<typename T>
void __quickSort3_2(T arr[], int l, int r) {
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
    swap(arr[rand() % (r - l + 1) + l], arr[l]);
    int lt = l;
    int gt = r + 1;
    for (int i = l + 1; i <= gt; ++i) {
        if (arr[i] > arr[l])
            swap(arr[i--], arr[--gt]);
        else if (arr[i] < arr[l])
            swap(arr[i], arr[++lt]);
    }
    swap(arr[l], arr[lt]);
    __quickSort3_2(arr, l, lt - 1);
    __quickSort3_2(arr, gt, r);
}


//单路快速排序
template<typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}

//双路快速排序
template<typename T>
void quickSort2(T arr[], int n) {
    srand(time(NULL));
    __quickSort2(arr, 0, n - 1);
}


//三路快速排序
template<typename T>
void quickSort3(T arr[], int n) {
    srand(time(NULL));
    __quickSort3(arr, 0, n - 1);
}

//三路快速排序 第二种实现
template<typename T>
void quickSort3_2(T arr[], int n) {
    srand(time(NULL));
    __quickSort3_2(arr, 0, n - 1);
}


#endif //ALGORITHMS_QUICKSORT_H
