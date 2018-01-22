#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int f(int n) {
	if (n == 1) return 1;
	return 2 * f(n/2);
}

int main() {
	for (int i = 1; i <= 50; ++i)
		cout << i << ": " << f(i) << endl;
	return 0;
}