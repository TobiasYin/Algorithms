//
// Created by Tobias on 2019/2/1.
//

#ifndef ALGORITHMS_MINHEAP_H
#define ALGORITHMS_MINHEAP_H

#include <iostream>
#include <cassert>

template<typename T>
class MinHeap {
private:
    T *data;
    int count;
    int capacity;

public:
    MinHeap(int c) {
        data = new T[capacity];
        count = 0;
        capacity = c;
    }

    ~MinHeap() {
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
        while (getParent(n) >= 0 && data[getParent(n)] >= data[n]) {
            std::swap(data[getParent(n)], data[n]);
            n = getParent(n);
        }
    }

    void shiftDown(int n) {
        while (2 * n + 1 < count) {
            int j = 2 * n + 1;
            if (j + 1 < count && data[j + 1] < data[j]) {
                j++;
            }
            if (data[n] > data[j]) {
                std::swap(data[n], data[j]);
                n = j;
            } else break;
        }
    }

};

#endif //ALGORITHMS_MINHEAP_H
