//
// Created by Tobias on 2019/2/7.
//

#ifndef ALGORITHMS_PRIMMST_H
#define ALGORITHMS_PRIMMST_H


#include "../Sorting/IndexMinHeap.h"
#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;

template<typename Graph, typename Weight>
class PrimMST {
private:
    Graph &g;
    IndexMinHeap<Weight> heap;
    vector<Edge<Weight> *> edgeTo;
    bool *marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit(int v) {
        assert(!marked[v]);
        marked[v] = true;
        typename Graph::adjIterator adj(g, v);
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
            int w = e->other(v);
            if (!marked[w]) {
                if (!edgeTo[w]) {
                    heap.add(w, e->wt());
                    edgeTo[w] = e;
                } else if (edgeTo[w]->wt() > e->wt()) {
                    heap.change(w, e->wt());
                    edgeTo[w] = e;
                }
            }
        }
    }

public:
    PrimMST(Graph &graph) : g(graph), heap(IndexMinHeap<Weight>(graph.E())) {
        marked = new bool[graph.V()];
        for (int i = 0; i < graph.V(); ++i) {
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();
        visit(0);
        while (!heap.isEmpty()) {
            int v = heap.extractMinIndex();
            assert(edgeTo[v]);
            mst.push_back(*edgeTo[v]);
            visit(v);
        }
        mstWeight = mst[0].wt();
        for (int j = 1; j < mst.size(); ++j) {
            mstWeight += mst[j].wt();
        }
    }

    ~PrimMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }


};


#endif //ALGORITHMS_PRIMMST_H
