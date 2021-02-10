#include <iostream>
using namespace std;

bool check[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	for (int i = 1; i < 10001; i++) {
		a = b = i;
		for (;;) {
			b += (a % 10);
			a /= 10;
			if (a==0) break;
			else if (b >= 10000) { b = 0; break; }
		}
		check[b] = true;
	}

	for (int i = 1; i < 10001; i++) {
		if (check[i] == false)cout << i << '\n';
	}

	return 0;
}