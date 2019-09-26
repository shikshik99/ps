#include <iostream>
using namespace std;

int arr[8];
int chk;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 7; i++) {
		if (arr[i] + 1 == arr[i + 1]) chk = 1;
		else if (arr[i] - 1 == arr[i + 1]) chk = -1;
		else { chk = 0; break; }
	}
	
	if (chk == 1)cout << "ascending\n";
	else if (chk == -1)cout << "descending\n";
	else cout << "mixed\n";

	return 0;
}