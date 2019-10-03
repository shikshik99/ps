#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str[100001];

bool cmp(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	
	sort(str, str + N, cmp);
	


	string tmp;
	for (int i = 0; i < N; i++) {
		if (tmp != str[i])
			cout << str[i] << '\n';
		tmp = str[i];
	}

	return 0;
}