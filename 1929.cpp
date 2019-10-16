#include <iostream>
using namespace std;

int arr[1000001];
bool check[1000001];
int a;

int main(void) {
	int N, M;
	cin >> M >> N;

	for (int i = 2; i*i<=1000000; i++) {
		if (check[i]) continue;
		for (int j = i*2; j <=1000000; j+=i)
		{
			check[j] = true;
		}
	}

	for (int i = M; i <= N; i++) {
		if (!check[i]) {
			arr[a++] = i;
		}
	}

	for (int i = 0; i < a; i++) {
		if (arr[i] == 1)continue;
		cout << arr[i] << '\n';
	}

	return 0;
}