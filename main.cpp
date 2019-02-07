//
// Created by Tobias on 2019/2/7.
//

#include <iostream>
#include <cassert>
#include "GraphTheory/DenseGraph.h"
#include "GraphTheory/SparseGraph.h"
#include "GraphTheory/ReadGraph.h"
#include "GraphTheory/Edge.h"
#include <string>
#include <iomanip>
#include "GraphTheory/LazyPrimMST.h"
#include <vector>
#include "GraphTheory/PrimMST.h"
#include "GraphTheory/KruskalMST.h"

using namespace std;

int main() {
    string filename = "D:\\Project\\Algorithms\\GraphTheory\\testG1.txt";
    int V = 8;
    cout << fixed << setprecision(2);
    DenseGraph<double> g1 = DenseGraph<double>(V, false);
    ReadGraph<DenseGraph<double>, double> r1(g1, filename);
    g1.show();

    cout << endl;
    SparseGraph<double> g2 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> r2(g2, filename);
    g2.show();

    cout << endl;
    //Test lazyPrimMst
    KruskalMST<SparseGraph<double>, double> mst(g2);
    vector<Edge<double>> res = mst.mstEdges();
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i]<<endl;
    }
    cout<<endl;
    cout<<mst.result();
    return 0;
}