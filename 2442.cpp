#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 0; j < N - i; j++) cout << " ";
		for (int k = 0; k < 2 * i - 1; k++)cout << "*";
		cout << "\n";
	}
}