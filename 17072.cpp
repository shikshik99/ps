#include <iostream>
using namespace std;

char ans[10001][10001];

int intensity_func(int R, int G, int B) {
	return 2126 * R + 7152 * G + 722 * B;
}

char cls(int a) {
	if (a >= 0 && a < 510000)
		return '#';
	else if (a >= 510000 && a < 1020000)
		return 'o';
	else if (a >= 1020000 && a < 1530000)
		return '+';
	else if (a >= 1530000 && a < 2040000)
		return '-';
	else if (a >= 2040000)
		return '.';
}

int main() {
	int N, M;
	int a, b, c;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a >> b >> c;
			ans[i][j] = cls(intensity_func(a, b, c));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}