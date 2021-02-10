#include <iostream>
using namespace std;

bool chk[10001];
int ans, anw;

void foo() {
	chk[1] = true;
	chk[0] = true;
	for (int i = 2; i < 10000; i++) {
		if (!chk[i]) {
			for (int j = i * 2; j < 10000; j += i) {
				chk[j] = 1;
			}
		}
	}
}

void foo1(int a) {
	int tmp = a / 2;
	if (!chk[tmp]) {
		ans = anw = tmp;
		return;
	}
	for (int i = 0; i <= tmp; i++) {
		if (!chk[tmp]) {
			if (!chk[a - tmp]) {
				ans = a - tmp;
				anw = tmp;
				return;
			}
		}
		tmp = tmp + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	foo();
	int a, T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a;
		foo1(a);
		cout << ans << ' ' << anw << '\n';
	}

	return 0;
}