//
// Created by Tobias on 2019/2/8.
//

#include <iostream>
#include <vector>
#include <cassert>
#include "GraphTheory/ReadGraph.h"
#include "GraphTheory/SparseGraph.h"
#include "GraphTheory/Edge.h"
#include "GraphTheory/Dijkstra.h"

using namespace std;

int main() {
    string filename = "D:\\Project\\Algorithms\\GraphTheory\\testG1.txt";
    int V = 8;
    SparseGraph<double> g = SparseGraph<double>(V, true);
    ReadGraph<SparseGraph<double>, double> r(g, filename);
    Dijkstra<SparseGraph<double>, double> dij(g, 0);
    vector<Edge<double >> v;
    dij.shortestPath(5, v);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    return 0;
}