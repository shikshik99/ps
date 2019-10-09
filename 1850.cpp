#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return a % b == 0 ? b : gcd(b, a % b);
}

int main() {
	ll a, b;
	cin >> a >> b;
	
	int ans = gcd(a, b);

	for (int i = 0; i < ans; i++)
		cout << 1;

	return 0;
}