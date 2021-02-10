#include <iostream>
using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int i, cls;

	for (i = 1; i < N + 1; i++) {
		cls = N - i + 1;
		for (int j = 0; j < i - 1; j++)cout << ' ';
		for (int k = 2*cls; k > 1; k--)cout << '*';
		cout << '\n';
	}
	for (i = 2; i <=N; i++) {
		cls = N - i;
		for (int j = 0; j < cls; j++)cout << ' ';
		for (int k = 0; k < 2 * i - 1; k++)cout << '*';
		cout << '\n';
	}
}