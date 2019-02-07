//
// Created by Tobias on 2019/2/7.
//

#ifndef ALGORITHMS_KRUSKALMST_H
#define ALGORITHMS_KRUSKALMST_H

#include <iostream>
#include <vector>
#include "../UnionFind.h"
#include "../Sorting/MinHeap.h"
#include "Edge.h"

using namespace std;

template<typename Graph, typename Weight>
class KruskalMST {
private:
    vector<Edge<Weight>> mst;
    Weight weight;
public:
    KruskalMST(Graph &graph) {
        MinHeap<Edge<Weight>> heap(graph.E());
        UnionFind find(graph.V());
        for (int i = 0; i < graph.V(); ++i) {
            typename Graph::adjIterator adj(graph, i);
            for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                if (e->v() < e->w())
                    heap.add(*e);
            }
        }
        while (!heap.isEmpty()) {
            Edge<Weight> e = heap.get();
            if (!find.isConnected(e.w(), e.v())) {
                find.unionElement(e.w(), e.v());
                mst.push_back(e);
            }
        }
        assert(mst.size() != 0);
        weight = mst[0].wt();
        for (int j = 1; j < mst.size(); ++j) {
            weight += mst[j].wt();
        }
    }

    ~KruskalMST() {}

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return weight;
    }
};


#endif //ALGORITHMS_KRUSKALMST_H
