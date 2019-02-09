//
// Created by Tobias on 2019/2/8.
//

#ifndef ALGORITHMS_DIJKSTRA_H
#define ALGORITHMS_DIJKSTRA_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "../Sorting/IndexMinHeap.h"
#include "Edge.h"

template<typename Graph, typename Weight>
class Dijkstra {
private:
    Graph &G;
    int s;
    Weight *distTo;
    bool *marked;
    vector<Edge<Weight> *> from;

public:
    Dijkstra(Graph &graph, int s) : G(graph) {
        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            distTo[i] = -1;
            marked[i] = false;
            from.push_back(NULL);
        }

        IndexMinHeap<Weight> heap(G.V());

        distTo[s] = Weight();
        marked[s] = true;
        heap.add(s, distTo[s]);
        while (!heap.isEmpty()) {
            int v = heap.extractMinIndex();
            marked[v] = true;
            typename Graph::adjIterator adj(G, v);
            for (Edge<Weight> *i = adj.begin(); !adj.end(); i = adj.next()) {
                int w = i->other(v);
                if (!marked[w]) {
                    if (from[w] == NULL || distTo[v] + i->wt() < distTo[w]) {
                        from[w] = i;
                        distTo[w] = distTo[v] + i->wt();
                        if (heap.contain(w)) {
                            heap.change(w, distTo[w]);
                        } else
                            heap.add(w, distTo[w]);
                    }
                }
            }
        }
    }

    ~Dijkstra() {
        delete[] distTo;
        delete[] marked;
    }

    Weight shortesdPathTo(int w) {
        return distTo[w];
    }

    bool hasPathTo(int w) {
        return marked[w];
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


#endif //ALGORITHMS_DIJKSTRA_H
