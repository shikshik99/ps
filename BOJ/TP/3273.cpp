#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;

int main(){
    int N, X, answer = 0;
    cin >> N, v.resize(N);
    for(int i = 0; i < N; i++) cin>> v[i];
    cin >> X;

    sort(v.begin(), v.end());
    int i = 0, j = N - 1;
    while(i != j){
        if(v[i] + v[j] == X) answer++, i++;
        else if(v[i] + v[j] < X) i++;
        else if(v[i] + v[j] > X) j--;
    }
    cout << answer;
}