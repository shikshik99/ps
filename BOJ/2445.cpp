#include <iostream>
using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int i, cls;

	for (i = 1; i < N+1; i++) {
		cls = N - i + 1;
		for (int j = 0; j < i; j++)cout << '*';
		for (int k = 0; k < 2 *cls  - 2; k++)cout << ' ';
		for (int j = 0; j < i; j++)cout << '*';
		cout << '\n';
	}
	for (int i = N-1; i >0; i--) {
		cls = N - i + 1;
		for (int j = 0; j < i; j++)cout << '*';
		for (int k = 0; k < 2 * cls - 2; k++)cout << ' ';
		for (int j = 0; j < i; j++)cout << '*';
		cout << '\n';
	}
}