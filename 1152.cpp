#include <iostream>
#include <string>
using namespace std;

string str;
int cnt;

int main() {
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ' &&str[i + 1] == ' ')cnt++;
		else if (str[i] != ' '&&str[i + 1] == NULL)cnt++;
	}
	cout << cnt;
	return 0;
}