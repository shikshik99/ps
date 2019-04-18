#include <iostream>
using namespace std;
int arr[1000001], ma, mi;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i==0)ma = mi = arr[i];
		if (arr[i] > ma)ma = arr[i];
		if (arr[i] < mi)mi = arr[i];
	}

	cout << mi << ' ' << ma << '\n';

	return 0;
}