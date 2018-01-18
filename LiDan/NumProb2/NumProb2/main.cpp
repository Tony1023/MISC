//
//  main.cpp
//  NumProb2
//
//  Created by Tony Lyu on 26/03/2017.
//  Copyright © 2017 Tony. All rights reserved.
//

#include <iostream>
int numbers[9];
using namespace std;

void search(int sum, int num, int curNum) {
    if (sum > 2017)
        return;
    if (num > 8) {
        if (sum == 2017) {
            for (int i = 1; i <= 8; ++i) {
                cout << numbers[i] << " ";
            }
            cout << "\n";
        }
        else
        return;
    }
    for (int i = curNum; i < 13; ++i) {
        numbers[num] = i;
        search(sum + i * i * i, num + 1, i);
    }
}

int main() {
    search(0, 1, 1);
}
