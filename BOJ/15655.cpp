#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, M;
int arr[10];
bool chk[10001];

void foo(int a, int idx) {
	if (a == M) {
		for (int i = 0; i < M; i++) cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; i++) {
		if (chk[arr[i]]) continue;
		v.push_back(arr[i]);
		chk[arr[i]] = 1;
		foo(a + 1, i + 1);
		v.pop_back();
		chk[arr[i]] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + N);

	foo(0, 0);

	return 0;
}