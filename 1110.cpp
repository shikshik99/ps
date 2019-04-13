#include <iostream>
using namespace std;
int N, cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c=100, sum=0;
	cin >> N;

	c = N;
	if (c < 10) {
		a = 0;
		b = c * 10;
		sum = c;
		c = b + sum;
	}
	else {
		a = c / 10;
		b = c % 10;
		sum = a + b;
		c = (b * 10) + (sum % 10);
	}
	cnt++;
	
	while (c != N) {
		if (c < 10) {
			a = 0;
			b = c * 10;
			sum = c;
			c = b + sum;
		}
		else {
			a = c / 10;
			b = c % 10;
			sum = a + b;
			c = (b * 10) + (sum % 10);
		}
		cnt++;
	}

	cout << cnt << '\n';

	return 0;
}