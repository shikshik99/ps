#include <iostream>
using namespace std;

int arr[10000];
int dus[100];
int k;
int j = 0, a = 0;


int main(void) {
	k = 0;
	int M, N;
	int sum = 0;
	cin >> M >> N;
	if (M > N)
		return 0;
	for (int i = M; i <= N; i++, j++)
	{
		arr[j] = i; a++;
	}
	for (j = 0; j < a; j++) {
		for (int i = 2; i <= arr[j]; i++)
		{
			int ans = arr[j];
			if (ans == 2) {
				dus[k] = ans;
				k++;
			}
			if (ans % i == 0)
				break;
			if (i == ans - 1) {
				dus[k] = ans;
				k++;
			}
		}
	}
	if (k == 0) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < k; i++)
		sum += dus[i];
	int min = dus[0];
	for (int i = 0; i < k - 1; i++)
		min = min < dus[i + 1] ? min : dus[i + 1];
	cout << sum << '\n' << min << '\n';

	return 0;
}