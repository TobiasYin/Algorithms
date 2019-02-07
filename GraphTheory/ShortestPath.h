//
// Created by Tobias on 2019/2/6.
//

#ifndef ALGORITHMS_SHORTESTPATH_H
#define ALGORITHMS_SHORTESTPATH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

template<typename Graph>
class ShortestPath {
private:
    Graph &G;
    int s;
    bool *visited;
    int *from;
    int *ord;

public:
    ShortestPath(Graph &graph, int source) : G(graph) {
        assert(source >= 0 && source < G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];
        ord = new int[G.V()];
        s = source;
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        queue<int> q;
        q.push(source);
        ord[source] = 0;
        visited[source] = true;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            typename Graph::adjIterator adj(G, temp);
            for (int i = adj.begin(); !adj.end(); i = adj.next()) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    ord[i] = ord[temp] + 1;
                    from[i] = temp;
                }
            }
        }
    }

    ~ShortestPath() {
        delete[] visited;
        delete[] from;
        delete[] ord;
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec) {
        assert(w >= 0 && w < G.V());
        stack<int> s;
        int p = w;
        while (p != -1) {
            s.push(p);
            p = from[p];
        }
        vec.clear();
        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
    }

    void showPath(int w) {
        vector<int> vec;
        path(w, vec);
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i == vec.size() - 1)
                cout << endl;
            else
                cout << " -> ";
        }
    }

    int length(int w) {
        assert(w >= 0 && w < G.V());
        return ord[w];
    }

};

#endif //ALGORITHMS_SHORTESTPATH_H
