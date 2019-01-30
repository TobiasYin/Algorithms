//
// Created by Tobias on 2019/1/27.
//

#ifndef ALGORITHMS_SORTTESTHELPER_H
#define ALGORITHMS_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;
namespace SortTestHelper {
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        for (int i = 1; i < n; ++i) {
            assert(arr[i - 1] <= arr[i]);
        }

        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
}
#endif //ALGORITHMS_SORTTESTHELPER_H