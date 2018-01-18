#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main() {
	ifstream fin("file.txt");
	int i = 0, j;
	while(!fin.fail()) {
		fin >> j;
		++i;
	}
	cout << i << endl;
	return 0;
}