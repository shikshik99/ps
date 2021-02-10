#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, str);

	for (int i = 0; i <= str.length(); i++) {
		if (65 <= str[i] && str[i] <= 90) {
			str[i] = ((str[i] + 13) > 90 ? str[i] - 13 : str[i] + 13);
		}

		else if (97 <= str[i] && str[i] <= 122) {
			str[i] = ((str[i] + 13) > 122 ? str[i] - 13 : str[i] + 13);
		}
	}

	cout << str;

	return 0;
}