#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, gcd=0;
	int c;
	cin >> c;
	if (c > 1000)
		return 0;
	for (int i = 0; i < c; i++)
	{
		cin >> a >> b;
		if (a > 45000 && b > 45000)
			return 0;
		for (int j = 1; j <= min(a, b); j++) {
			if (a%j==0&&b%j==0)
				gcd = j;
		}
		cout << a * b / gcd<<'\n';
	}
	return 0;
}