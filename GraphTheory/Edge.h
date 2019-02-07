//
// Created by Tobias on 2019/2/7.
//

#ifndef ALGORITHMS_EDGE_H
#define ALGORITHMS_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

template<typename Weight>
class Edge {
private:
    int a, b;
    Weight weight;
public:
    Edge(int a, int b, Weight weight) {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    Edge() {}

    ~Edge() {}

    Weight wt() {
        return weight;
    }

    int v() { return a; }

    int w() { return b; }

    int other(int x) {
        assert(x == a || x == b);
        return x == a ? b : a;
    }

    friend ostream &operator<<(ostream &os, const Edge &e) {
        os << e.a << "--" << e.b << ": " << e.weight;
        return os;
    }

    bool operator<(Edge<Weight> &e) {
        return weight < e.wt();
    }

    bool operator>(Edge<Weight> &e) {
        return weight > e.wt();
    }

    bool operator<=(Edge<Weight> &e) {
        return weight <= e.wt();
    }

    bool operator>=(Edge<Weight> &e) {
        return weight >= e.wt();
    }

    bool operator==(Edge<Weight> &e) {
        return weight == e.wt();
    }

    bool operator!=(Edge<Weight> &e) {
        return weight != e.wt();
    }

};

#endif //ALGORITHMS_EDGE_H
