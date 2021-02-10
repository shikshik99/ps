#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, cls, a;

	cin >> T;
	for (int i = 1; i < T + 1; i++) {
		cls = T - i; a = i;
		while (cls--)cout << ' ';
		while (a--)cout << '*';
		cout << '\n';
	}

	for (int i = T; i > 1; i--) {
		cls = i - 1;
		a = T - i + 1;
		while (a--)cout << ' ';
		while (cls--)cout << '*';
		cout << '\n';
	}

	return 0;
}