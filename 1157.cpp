#include <iostream>
#include <string>
using namespace std;
int arr[27], ma, cnt, mem;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] - 'A' > 27) { arr[str[i] - 'a']++; }
		else { arr[str[i] - 'A']++; }
	}

	for (int i = 0; i < 27; i++) {
		if (ma < arr[i])ma = arr[i];
	}

	for (int i = 0; i < 27; i++) {
		if (ma == arr[i]) { cnt++; mem = i; }
	}

	str[0] = mem + 'A';
	if (cnt > 1)cout << '?' << '\n';
	else cout << str[0] << '\n';

	return 0;
}