//
// Created by Tobias on 2019/2/7.
//

#ifndef ALGORITHMS_LAZYPRIMMST_H
#define ALGORITHMS_LAZYPRIMMST_H

#include "../Sorting/MinHeap.h"
#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;

template<typename Graph, typename Weight>
class LazyPrimMST {
private:
    Graph &g;
    MinHeap<Edge<Weight>> heap;
    bool *marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;
    int count = 0;

    void visit(int v) {
        assert(!marked[v]);
        marked[v] = true;
        count++;
        typename Graph::adjIterator adj(g, v);
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
            if (!marked[e->other(v)]) {
                heap.add(*e);
            }
        }
    }

public:
    LazyPrimMST(Graph &graph) : g(graph), heap(MinHeap<Edge<Weight>>(graph.E())) {
        marked = new bool[graph.V()];
        for (int i = 0; i < graph.V(); ++i) {
            marked[i] = false;
        }
        mst.clear();
        visit(0);
        while (count != graph.V()) {
            Edge<Weight> e = heap.get();
            if (marked[e.v()] == marked[e.w()])
                continue;

            mst.push_back(e);
            if (!marked[e.v()])
                visit(e.v());
            else
                visit(e.w());
        }
        mstWeight = mst[0].wt();
        for (int j = 1; j < mst.size(); ++j) {
            mstWeight += mst[j].wt();
        }
    }

    ~LazyPrimMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }


};


#endif //ALGORITHMS_LAZYPRIMMST_H
