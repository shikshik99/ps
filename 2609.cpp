#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int A, B;
	int ma, mi;
	int ans, ans1;
	cin >> A >> B;

	ma = max(A, B);
	mi = min(A, B);
	
	ans = gcd(ma, mi);
	ans1 = lcm(ma, mi);

	cout << ans << '\n' << ans1;

	return 0;
}