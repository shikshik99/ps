#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#define ll unsigned long long
using namespace std;

int arr[6] = { 500,100,50,10,5,1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, gus, ans = 0;
	cin >> a;
	gus = 1000 - a;
	for (int i = 0; i < 6; i++) {
		ans += gus / arr[i];
		gus = gus % arr[i];
	}
	cout << ans;

	return 0;
}