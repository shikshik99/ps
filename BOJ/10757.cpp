#include <iostream>
#include <string>
using namespace std;

string MAX;
string MIN;
string sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> MAX;
	cin >> MIN;
	 
	int max = MAX.size() > MIN.size() ? MAX.size() : MIN.size();
	int min = MAX.size() < MIN.size() ? MAX.size() : MIN.size();

	if (MIN.size() > MAX.size()) MAX.swap(MIN);
	
	for (int i = 0; i < max - min; i++) {
		MIN = '0' + MIN;
	}
	
	int carry = 0;
	
	sum = MAX;

	for (int i = max-1; i >= 0; i--) {
		if (i == 0) {
			if (((MAX[0] - '0') + (MIN[0] - '0') + carry) >= 10) {
				sum[0] = ((MAX[0] - '0') + (MIN[0] - '0') + carry - 10) + '0';
				cout << '1';
			}	
			else
			{
				sum[0] = ((MAX[0] - '0') + (MIN[0] - '0') + carry) + '0';
			}	
		}
			if (((MAX[i] - '0') + (MIN[i] - '0') + carry) >= 10) {
				sum[i] = ((MAX[i] - '0') + (MIN[i] - '0') + carry - 10) + '0';
				carry = 1;
		}
		else {
				sum[i] = ((MAX[i] - '0') + (MIN[i] - '0') + carry) + '0';
				carry = 0;
		}
	}

	for (int i = 0;	i < sum.size(); i++)
		cout << sum[i];

	return 0;
}