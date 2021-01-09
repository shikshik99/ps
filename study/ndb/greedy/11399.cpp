#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#define ll unsigned long long
using namespace std;

int arr[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0, tmp = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		tmp = tmp + arr[i];
		ans = ans + tmp;
	}
	cout << ans;	

	return 0;
}