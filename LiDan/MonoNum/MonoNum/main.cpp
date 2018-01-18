//
//  main.cpp
//  MonoNum
//
//  Created by Tony Lyu on 26/02/2017.
//  Copyright © 2017 Tony. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> num;
void generate(int dig) {
    if (dig == -1) {
        for (vector<int>::iterator iter = num.begin(); iter != num.end(); ++iter) {
            cout << *iter;
        }
        cout << endl;
        return;
    }
    for (int i = dig; i >= 0; --i) {
        num.push_back(i);
        generate(i-1);
        num.pop_back();
    }
}

int main() {
    generate(9);
    return 0;
}

