#include <iostream>
using namespace std;
#define MAX 10000001
int arr[10000001];


int main() {
	arr[1] = 5;
	for (int i = 2; i <= MAX - 1; i++)arr[i] = (arr[i - 1] + (i * 3) + 1) % 45678;
	
	int T;
	cin >> T;
	
	cout << arr[T] << '\n';

	return 0;
}