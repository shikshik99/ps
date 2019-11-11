#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(int a, int b) {
	return a < b;
}

int main() {
	int a;
	cin >> a;
	vector<int> intV;
	int b;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		intV.push_back(b);
	}
	sort(intV.begin(), intV.end(),Compare);
	for (int i = 0; i < a; i++)
		cout << intV[i] << '\n';

	return 0;
}