//
//  main.cpp
//  MathProblem
//
//  Created by Tony Lyu on 26/03/2017.
//  Copyright © 2017 Tony. All rights reserved.
//

#include <iostream>
using namespace std;

bool qualified(int n1, int n2) {
    int a = n1 / 100000;
    n1 -= a * 100000;
    n1 *= 10;
    n1 += a;
    cout << n1 << " " << n2 << "\n";
    return ( n1 == n2 );
}
int main() {
    for (int xyz = 100; xyz < 1000; ++xyz) {
        for (int uvw = 100; uvw < 1000; ++uvw) {
            int num1 = xyz * 1000 + uvw, num2 = xyz + uvw * 1000;
            if (num1 % 33 != 0 || num2 % 25 != 0)
                continue;
            int num3 = num1 / 33 * 38, num4 = num2 / 25 * 32;
            if (num3 / 1000000 == 0 && num4 / 1000000 == 0 && qualified(num3, num4)) {
                cout << num1 << "\n";
                return 0;
            }
        }
    }
}
