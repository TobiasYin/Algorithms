//
// Created by Tobias on 2019/2/1.
//

#ifndef ALGORITHMS_INDEXHEAP_H
#define ALGORITHMS_INDEXHEAP_H

#include <iostream>
#include <cassert>

template<typename T>
class IndexHeap {
private:
    T *data;
    int *index;
    int *rev;
    int count;
    int capacity;

public:
    IndexHeap(int capacity) {
        data = new T[capacity];
        count = 0;
        this->capacity = capacity;
        index = new int[capacity];
        rev = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            rev[i] = -1;
        }
    }

    IndexHeap(T arr[], int n) {
        data = new T[n];
        index = new int[n];
        capacity = n;
        count = n;
        for (int i = 0; i < n; ++i) {
            data[i] = arr[i];
            index[i] = i;
            rev[i] = i;
        }
        for (int i = (count - 1) / 2; i >= 0; --i) {
            shiftDown(i);
        }
    }

    ~IndexHeap() {
        delete[] data;
        delete[] index;
        delete[] rev;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void add(int i, T element) {
        assert(count + 1 <= capacity);
        assert(i >= 0 && i < capacity);
        data[i] = element;
        index[count] = i;
        rev[i] = count;
        shiftUp(count++);
    }

    T getMax() {
        assert(!isEmpty());
        T ret = data[index[0]];
        index[0] = index[--count];
        rev[index[0]] = 0;
        rev[index[count]] = -1;
        shiftDown(0);
        return ret;
    }

    int getMaxIndex() {
        assert(!isEmpty());
        return index[0];
    }

    T getItem(int i) {
        assert(contain(i));
        return data[i];
    }

    void change(int i, T element) {
        assert(contain(i));
        data[i] = element;
        int j = rev[i];
        shiftUp(j);
        shiftDown(j);
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
        while (getParent(n) >= 0 && data[index[getParent(n)]] <= data[index[n]]) {
            std::swap(index[getParent(n)], index[n]);
            rev[index[getParent(n)]] = getParent(n);
            rev[index[n]] = n;
            n = getParent(n);
        }
    }

    void shiftDown(int n) {
        while (2 * n + 1 < count) {
            int j = 2 * n + 1;
            if (j + 1 < count && data[index[j + 1]] > data[index[j]]) {
                j++;
            }
            if (data[index[n]] < data[index[j]]) {
                std::swap(index[n], index[j]);
                rev[index[n]] = n;
                rev[index[j]] = j;
                n = j;
            } else break;
        }
    }

    bool contain(int i) {
        return rev[i] == -1;
    }

};

#endif //ALGORITHMS_INDEXHEAP_H
