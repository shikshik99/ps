#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
bool chk[10];
int N, M;

void foo(int a) {
	if (a == M) {
		for (int i = 0; i < M; i++) cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (chk[i]) continue;
		v.push_back(i);
		chk[i] = 1;
		foo(a + 1);
		v.pop_back();
		chk[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	foo(0);

	return 0;
}