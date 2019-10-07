#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[10];
int foo;

int main() {
	string N;
	cin >> N;

	for (int i = 0; i < N.size(); i++) {
		arr[N[i] - '0']++;
	}
	arr[6] += arr[9];
	foo = arr[0];

	if (!(arr[6] % 2)) arr[6] /= 2;
	else arr[6] = arr[6] / 2 + 1;
	
	for (int i = 0; i < 8; i++) {
		foo = max(foo, arr[i + 1]);
	}
	cout << foo << '\n';

	return 0;
}