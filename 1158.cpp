#include <iostream>
using namespace std;

bool chk[10001];
int arr[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	int a = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			a += 1;
			if (a > N) a %= N;
			if (chk[a]) {
				while (chk[a]) {
					a += 1;
					if (a > N) a %= N;
				}
			}
		}
		chk[a] = true;
		arr[i] = a;
	}
	
	cout << '<' << arr[0];

	for (int i = 1; i < N; i++) {
		cout << ',' << ' ' << arr[i];
	}
	
	cout << '>' << ' ';
	return 0;
}