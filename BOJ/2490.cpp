#include <iostream>
using namespace std;

int A;
int cnt0, cnt1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> A;
			if (A) cnt1++;
			else cnt0++;
		}
		if (cnt0 == 1 && cnt1 == 3) cout << 'A' << '\n';
		else if (cnt0 == 2 && cnt1 == 2)cout << 'B' << '\n';
		else if (cnt0 == 3 && cnt1 == 1)cout << 'C' << '\n';
		else if (cnt0 == 4)cout << 'D' << '\n';
		else if (cnt1 == 4)cout << 'E' << '\n';
		cnt0 = cnt1 = 0;
	}
	return 0;
}