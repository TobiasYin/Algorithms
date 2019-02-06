//
// Created by Tobias on 2019/2/3.
//


#include <iostream>

using namespace std;

struct Test {
    int i = 1;
    int j = 2;

    Test(int i, int j) {
        this->i = i;
        this->j = j;
    }

    void hello() {
        cout << "hello " << this->i << " " << this->j << " " << endl;
    }
};

int main() {
    Test *t =new Test(1, 2);
    t.hello();
    return 0;
}