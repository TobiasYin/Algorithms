////
//// Created by Tobias on 2019/2/6.
////
//
//#include <iostream>
//#include <ctime>
//#include "GraphTheory/SparseGraph.h"
//#include "GraphTheory/DenseGraph.h"
//#include "GraphTheory/ReadGraph.h"
//#include "GraphTheory/Component.h"
//#include "GraphTheory/Path.h"
//#include "GraphTheory/ShortestPath.h"
//
//using namespace std;
//
//
//int testmain() {
//    int N = 20;
//    int M = 100;
//    srand(time(NULL));
//    SparseGraph g1(N, false);
//
//    for (int i = 0; i < M; ++i) {
//        int a = rand() % N;
//        int b = rand() % N;
//        g1.addEdge(a, b);
//    }
//
//    for (int j = 0; j < N; ++j) {
//        cout << j << " : ";
//        SparseGraph::adjIterator adj(g1, j);
//        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
//            cout << i << ", ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//    DenseGraph<double> g2(N, false);
//
//    for (int i = 0; i < M; ++i) {
//        int a = rand() % N;
//        int b = rand() % N;
//        g2.addEdge(a, b);
//    }
//
//    for (int j = 0; j < N; ++j) {
//        cout << j << " : ";
//        DenseGraph::adjIterator adj(g2, j);
//        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
//            cout << i << ", ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//
//    return 0;
//}
//
//int basemain() {
//    int V = 13;
//    int E = 13;
//    string filename = "D:\\Project\\Algorithms\\GraphTheory\\testG1.txt";
//    string filename2 = "D:\\Project\\Algorithms\\GraphTheory\\testG2.txt";
//    DenseGraph g1(V, false);
//    SparseGraph g2(V, false);
//    ReadGraph<DenseGraph> r1(g1, filename);
//    ReadGraph<SparseGraph> r2(g2, filename);
//    g1.show();
//    g2.show();
//    Component<SparseGraph> c1(g2);
//    SparseGraph g3(6, false);
//    ReadGraph<SparseGraph> r3(g3, filename2);
//    Component<SparseGraph> c2(g3);
//    cout << c1.count()<<" "<<c2.count()<<endl;
//    Path<SparseGraph> p(g3,0);
//    p.showPath(5);
//    ShortestPath<SparseGraph> sp(g3,0);
//    sp.showPath(5);
//}