#include <iostream>
using namespace std;
int d;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y;
	cin >> x >> y;

	for (int i = 1; i < x; i++) {
		if (x == 1) break;
		if (i == 4 || i == 6 || i == 9 || i == 11)d += 30;
		else if (i == 2)d += 28;
		else d += 31;
	}
	d += y;
	d %= 7;
	
	switch (d) {
	case 0:
		cout << "SUN\n";
		return 0;
	case 1:
		cout << "MON\n";
		return 0;
	case 2:
		cout << "TUE\n";
		return 0;
	case 3:
		cout << "WED\n";
		return 0;
	case 4:
		cout << "THU\n";
		return 0;
	case 5:
		cout << "FRI\n";
		return 0;
	case 6:
		cout << "SAT\n";
		return 0;
	}

	return 0;
}