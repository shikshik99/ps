#include <iostream>
using namespace std;

int main() {
	int N, cnt = 0;
	int a, b, c;

	cin >> N;

	for (int i = 1; i < N + 1; i++) {
		if (i < 100)cnt++;
		else {
			a = i / 100;
			c = i % 10;
			b = (i % 100) / 10;
			if (b-a == c-b)cnt++;
		}
	}
	
	cout << cnt << '\n';

	return 0;
}