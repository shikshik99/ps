#include<iostream>
#include<string>
using namespace std;
int F[10];

int main() {
	int A;
	int B;
	int C;
	int D;
	cin >> A >> B >> C;
	D = A * B*C;
	string awr;
	awr = to_string(D);
	int len = awr.length();
	for (int i = 0; i < len; i++) {
		F[awr[i] - '0']++;
	}
	for (int i = 0; i < 10; i++)
		cout << F[i] << endl;
}