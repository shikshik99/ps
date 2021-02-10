#include <iostream>
#include <algorithm>
using namespace std;

double arr[10001];
double M, sum;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		M = max(M, arr[i]);
	}

	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] / M * 100;
		sum += arr[i];
	}

	cout << fixed;
	cout.precision(2);
	cout << sum / N;

	return 0;
}