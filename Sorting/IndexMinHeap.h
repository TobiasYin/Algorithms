//
// Created by Tobias on 2019/2/1.
//

#ifndef ALGORITHMS_INDEXMINHEAP_H
#define ALGORITHMS_INDEXMINHEAP_H

//#include <iostream>
//#include <cassert>
//
//template<typename T>
//class IndexMinHeap {
//private:
//    T *data;
//    int *index;
//    int *rev;
//    int count;
//    int capacity;
//
//public:
//    IndexMinHeap(int capacity) {
//        data = new T[capacity];
//        count = 0;
//        this->capacity = capacity;
//        index = new int[capacity];
//        rev = new int[capacity];
//        for (int i = 0; i < capacity; ++i) {
//            rev[i] = -1;
//        }
//    }
//
//    IndexMinHeap(T arr[], int n) {
//        data = new T[n];
//        index = new int[n];
//        capacity = n;
//        count = n;
//        for (int i = 0; i < n; ++i) {
//            data[i] = arr[i];
//            index[i] = i;
//            rev[i] = i;
//        }
//        for (int i = (count - 1) / 2; i >= 0; --i) {
//            shiftDown(i);
//        }
//    }
//
//    ~IndexMinHeap() {
//        delete[] data;
//        delete[] index;
//        delete[] rev;
//    }
//
//    int size() {
//        return count;
//    }
//
//    bool isEmpty() {
//        return count == 0;
//    }
//
//    void add(int i, T element) {
//        assert(count + 1 <= capacity);
//        assert(i >= 0 && i < capacity);
//        data[i] = element;
//        index[count] = i;
//        rev[i] = count;
//        shiftUp(count++);
//    }
//
//    T getMin() {
//        assert(!isEmpty());
//        T ret = data[index[0]];
//        index[0] = index[--count];
//        rev[index[0]] = 0;
//        rev[index[count]] = -1;
//        shiftDown(0);
//        return ret;
//    }
//
//    int getMinIndex() {
//        assert(!isEmpty());
//        return index[0];
//    }
//
//    T getItem(int i) {
//        assert(contain(i));
//        return data[i];
//    }
//
//    void change(int i, T element) {
//        assert(contain(i));
//        data[i] = element;
//        int j = rev[i];
//        shiftUp(j);
//        shiftDown(j);
//    }
//
//private:
//    int leftChild(int n) {
//        return 2 * n + 1;
//    }
//
//    int rightChild(int n) {
//        return 2 * n + 2;
//    }
//
//    int getParent(int n) {
//        if (n == 0) return -1;
//        return (n - 1) / 2;
//    }
//
//    void shiftUp(int n) {
//        while (getParent(n) >= 0 && data[index[getParent(n)]] >= data[index[n]]) {
//            std::swap(index[getParent(n)], index[n]);
//            rev[index[getParent(n)]] = getParent(n);
//            rev[index[n]] = n;
//            n = getParent(n);
//        }
//    }
//
//    void shiftDown(int n) {
//        while (2 * n + 1 < count) {
//            int j = 2 * n + 1;
//            if (j + 1 < count && data[index[j + 1]] < data[index[j]]) {
//                j++;
//            }
//            if (data[index[n]] > data[index[j]]) {
//                std::swap(index[n], index[j]);
//                rev[index[n]] = n;
//                rev[index[j]] = j;
//                n = j;
//            } else break;
//        }
//    }
//
//    bool contain(int i) {
//        return rev[i] == -1;
//    }
//
//};

using namespace std;


template<typename Item>
class IndexMinHeap {

private:
    Item *data;
    int *indexes;
    int *reverse;

    int count;
    int capacity;

    void shiftUp(int k) {

        while (k > 1 && data[indexes[k / 2]] > data[indexes[k]]) {
            swap(indexes[k / 2], indexes[k]);
            reverse[indexes[k / 2]] = k / 2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k) {

        while (2 * k <= count) {
            int j = 2 * k;
            if (j + 1 <= count && data[indexes[j]] > data[indexes[j + 1]])
                j += 1;

            if (data[indexes[k]] <= data[indexes[j]])
                break;

            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    IndexMinHeap(int capacity) {

        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];

        for (int i = 0; i <= capacity; i++)
            reverse[i] = 0;

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMinHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void add(int index, Item item) {
        assert(count + 1 <= capacity);
        assert(index + 1 >= 1 && index + 1 <= capacity);

        index += 1;
        data[index] = item;
        indexes[count + 1] = index;
        reverse[index] = count + 1;
        count++;
        shiftUp(count);
    }

    Item extractMin() {
        assert(count > 0);

        Item ret = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMinIndex() {
        assert(count > 0);

        int ret = indexes[1] - 1;
        swap(indexes[1], indexes[count]);
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    Item getMin() {
        assert(count > 0);
        return data[indexes[1]];
    }

    int getMinIndex() {
        assert(count > 0);
        return indexes[1] - 1;
    }

    bool contain(int index) {

        return reverse[index + 1] != 0;
    }

    Item getItem(int index) {
        assert(contain(index));
        return data[index + 1];
    }

    void change(int index, Item newItem) {

        assert(contain(index));
        index += 1;
        data[index] = newItem;

        shiftUp(reverse[index]);
        shiftDown(reverse[index]);
    }

};

#endif //ALGORITHMS_INDEXHEAP_H
