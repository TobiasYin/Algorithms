//
// Created by Tobias on 2019/2/1.
//

#ifndef ALGORITHMS_MAXHEAP_H
#define ALGORITHMS_MAXHEAP_H

#include <iostream>
#include <cassert>

template<typename T>
class MaxHeap {
private:
    T *data;
    int count;
    int capacity;

public:
    MaxHeap(int capacity) {
        data = new T[capacity];
        count = 0;
        this->capacity = capacity;
    }

    MaxHeap(T arr[], int n) {
        data = new T[n];
        capacity = n;
        count = n;
        for (int i = 0; i < n; ++i) {
            data[i] = arr[i];
        }
        for (int i = (count - 1) / 2; i >= 0; --i) {
            shiftDown(i);
        }
    }

    ~MaxHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void add(T element) {
        assert(count + 1 <= capacity);
        data[count] = element;
        shiftUp(count++);
    }

    T get() {
        assert(!isEmpty());
        T ret = data[0];
        data[0] = data[--count];
        shiftDown(0);
        return ret;
    }

private:
    int leftChild(int n) {
        return 2 * n + 1;
    }

    int rightChild(int n) {
        return 2 * n + 2;
    }

    int getParent(int n) {
        if (n == 0) return -1;
        return (n - 1) / 2;
    }

    void shiftUp(int n) {
        while (getParent(n) >= 0 && data[getParent(n)] <= data[n]) {
            std::swap(data[getParent(n)], data[n]);
            n = getParent(n);
        }
    }

//    void shiftDown(int n) {
//        while (leftChild(n) < count) {
//            if (rightChild(n) >= count) {
//                if (data[n] < data[leftChild(n)])
//                    std::swap(data[n], data[leftChild(n)]);
//                break;
//            }
//
//            if (data[n] >= data[leftChild(n)] && data[n] >= data[rightChild(n)]) {
//                break;
//            } else if (data[rightChild(n)] >= data[leftChild(n)] && data[rightChild(n)] >= data[n]) {
//                std::swap(data[rightChild(n)], data[n]);
//                n = rightChild(n);
//            } else if (data[leftChild(n)] >= data[rightChild(n)] && data[leftChild(n)] >= data[n]) {
//                std::swap(data[leftChild(n)], data[n]);
//                n = leftChild(n);
//            }
//        }
//    }
    void shiftDown(int n) {
        while (2 * n + 1 < count) {
            int j = 2 * n + 1;
            if (j + 1 < count && data[j + 1] > data[j]) {
                j++;
            }
            if (data[n] < data[j]) {
                std::swap(data[n], data[j]);
                n = j;
            } else break;
        }
    }

};

#endif //ALGORITHMS_MAXHEAP_H
