#include <iostream>
using namespace std;

int arr[100001];
int chk[100001];

int main() {
	int N, X, tmp = 0, cnt = 0;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] < X) chk[i] = true;
	}
	for (int i = 0; i < N; i++) {
		if (chk[i]) cout << arr[i] << ' ';
	}
}