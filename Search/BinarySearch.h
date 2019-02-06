//
// Created by Tobias on 2019/2/3.
//

#ifndef ALGORITHMS_BINARYSEARCH_H
#define ALGORITHMS_BINARYSEARCH_H

#include<iostream>

using namespace std;

template<typename T>
// 二分查找法, 在有序数组中查找指定元素
// 返回值为待查找元素的索引,如果没找到,则返回-1
int binarySearch(T arr[], int n, T target) {
    // 在目标arr[i,r]中查找target.
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > target)
            r = mid - 1;
        else if (arr[mid] < target)
            l = mid + 1;
        else return mid;
    }
    return -1;
}

#endif //ALGORITHMS_BINARYSEARCH_H
