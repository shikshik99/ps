#include <iostream>
using namespace std;

int arr[100];
int ans;
int cnt = 0;

int main() {
	int n = 0;
	cin >> n; if (n > 100)return 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 1)continue;
		if (arr[i] == 2)
			cnt++;
		for (int j = 2; j <= arr[i]-1; j++)
		{
			ans = arr[i];
			if (ans%j == 0)break;
			if (j == ans - 1)
				cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}