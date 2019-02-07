//
// Created by Tobias on 2019/2/4.
//

#ifndef ALGORITHMS_UNIONFIND_H
#define ALGORITHMS_UNIONFIND_H

#include<iostream>
#include<cassert>

using namespace std;

class UnionFind {
private:
    int *parent;
    int *rank;
    int count;
public:
    UnionFind(int size) {
        parent = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) {
            rank[i] = 1;
            parent[i] = i;
        }
        count = size;
    }

    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

//    int find(int p) {
//        assert(p >= 0 and p < count);
//        while (p != parent[p]) {
//            parent[p] = parent[parent[p]];
//            p = parent[p];
//        }
//        return p;
//    }

    int find(int p) {
        assert(p >= 0 and p < count);
        if (p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    void unionElement(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        if (rank[rootP] < rank[rootQ]) {
            parent[rootP] = rootQ;
        } else if (rank[rootQ] < rank[rootP]) {
            parent[rootQ] = rootP;
        } else {
            parent[rootP] = rootQ;
            rank[rootQ] += 1;
        }
    }


    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

};

#endif //ALGORITHMS_UNIONFIND_H
