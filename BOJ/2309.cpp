#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];

int main() {
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += arr[i];
	bool chk = 0;

	for (int i = 0; i < 9; i++) {
		if (chk)break;
		for (int j = i + 1; j < 9; j++) {
			if (sum - (arr[i] + arr[j]) == 100) { arr[i] = 0; arr[j] = 0; chk = 1; break; }
		}
	}

	sort(arr, arr + 9);
	for (int i = 2; i < 9; i++)cout << arr[i] << '\n';

	return 0;
}