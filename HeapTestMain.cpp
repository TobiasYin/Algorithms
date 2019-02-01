//
// Created by Tobias on 2019/2/1.
//

#include<iostream>
#include "Sorting/MaxHeap.h"
#include <ctime>
using namespace std;

void heapTest(MaxHeap<int>,int);

int nomain(){
    int size = 1000000;
    MaxHeap<int> mp = MaxHeap<int>(size);
    heapTest(mp,size);
    cout<<"Test Success!"<<endl;
    return 0;
}

void heapTest(MaxHeap<int> mp, int n){
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        mp.add(rand()%INT32_MAX);
    }
    int x = mp.get();
    while(!mp.isEmpty()){
        int t = mp.get();
        assert(x >= t);
        x = t;
    }
}