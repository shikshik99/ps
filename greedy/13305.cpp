#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#define ll unsigned long long
using namespace std;

int road[100001];
int gas[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll N, ans = 0, pivot, cnt = 0;
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> road[i];
	for (int i = 0; i < N; i++) cin >> gas[i];
	pivot = gas[0];
	for (int i = 0; i < N - 1; i++) {
		cnt += road[i];
		if (pivot > gas[i + 1]) {
			ans += pivot * cnt;
			pivot = gas[i + 1];
			cnt = 0;
		}
		if (i + 1 == N) break;
	}
	ans += pivot * cnt;
	cout << ans;

	return 0;
}