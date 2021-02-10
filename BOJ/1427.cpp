#include <iostream>
#include <string>
using namespace std;

int cnt[10];
string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		cnt[str[i] - '0']++;
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i;
		}
	}

	return 0;
}