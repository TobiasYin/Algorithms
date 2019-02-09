//
// Created by Tobias on 2019/2/8.
//

#ifndef ALGORITHMS_BELLMANFORD_H
#define ALGORITHMS_BELLMANFORD_H

#include <iostream>
#include <vector>
#include <stack>
#include "../UnionFind.h"
#include "../Sorting/MinHeap.h"
#include "Edge.h"

using namespace std;

template<typename Graph, typename Weight>
class BellmanFord {
private:
    Graph &G;
    int s;
    Weight *distTo;
    vector<Edge<Weight> *> from;
    bool hasNegativeCycle;

    bool detectCycle() {

        for (int i = 0; i < G.V(); ++i) {
            typename Graph::adjIterator adj(G, i);
            for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                if (!from[e->w()] == NULL || distTo[e->v()] + e->wt() < distTo[e->w()]) {
                    return true;
                }
            }
        }
    }

public:
    BellmanFord(Graph &graph, int s) : G(graph) {
        this->s = s;
        distTo = new Weight[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            from.push_back(NULL);
        }
        distTo[s] = Weight();

        for (int pass = 1; pass < G.V(); ++pass) {
            for (int i = 0; i < G.V(); ++i) {
                typename Graph::adjIterator adj(G, i);
                for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                    if (!from[e->w()] == NULL || distTo[e->v()] + e->wt() < distTo[e-   >w()]) {
                        distTo[e->w()] = distTo[e->v()] + e->wt();
                        from[e->w()] = e;
                    }
                }
            }
        }

        hasNegativeCycle = detectCycle();
    }

    ~BellmanFord() {
        delete[] distTo;
    }

    Weight shortesdPathTo(int w) {
        return distTo[w];
    }

    bool negativeCycle() {
        return hasNegativeCycle;
    }

    bool hasPathTo(int w) {
        return from[w] != NULL;
    }


    void shortestPath(int w, vector<Edge<Weight>> &vec) {
        stack<Edge<Weight> *> ss;
        Edge<Weight> *e = from[w];
        ss.push(e);
        while (e->v() != s) {
            e = from[e->v()];
            ss.push(e);
        }
        vec.clear();
        while (!ss.empty()) {
            vec.push_back(*(ss.top()));
            ss.pop();
        }
    }
};

#endif //ALGORITHMS_BELLMANFORD_H
