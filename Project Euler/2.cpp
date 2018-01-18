#include <iostream>
using namespace std;

int main(){
	unsigned long int f[100], sum = 0;
	f[0] = f[1] = 1;
	cout << 1 << " " << 1 << " ";
	for (int i = 2; i < 100; ++i) {
		f[i] = f[i-1] + f[i-2];
		cout << f[i] << " ";
		if (f[i] < 4000000)
			sum += f[i];
		else
			break;
	}
	cout << endl << sum/2 << endl;
	return 0;
}