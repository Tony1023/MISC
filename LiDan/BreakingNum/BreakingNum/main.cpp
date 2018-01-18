//
//  main.cpp
//  BreakingNum
//
//  Created by Tony Lyu on 26/02/2017.
//  Copyright © 2017 Tony. All rights reserved.
//

#include <iostream>
using namespace std;
int nanshou[6];
int N = 6;
void breakDown(int x, int diff, int count) {
    if (diff < x) {
        if (diff != 0)
            return;
        cout << "6 = " << nanshou[0];
        for (int i = 1; i < count; ++i) {
            cout << "+" << nanshou[i];
        }
        cout << endl;
        return;
    }
    for (int i = x; i <= diff; ++i) {
        nanshou[count] = i;
        breakDown(i, diff-i, count+1);
    }
}

int main() {
    cin >> N;
    breakDown(1, 6, 0);
    
}
