#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> sensor;
vector <int> v;

int main(){
    int N, K;
    cin >> N >> K;
    sensor.resize(N);
    for(int i = 0; i < N; i++) cin >> sensor[i];
    sort(sensor.begin(), sensor.end());
    sensor.erase(unique(sensor.begin(), sensor.end()), sensor.end());
    for(int i = 0; i < sensor.size() - 1; i++) v.push_back(sensor[i+1] - sensor[i]);
    sort(v.begin(), v.end(), greater<>());
    
    int answer = sensor[sensor.size() - 1] - sensor[0];
    auto it = v.begin(); K--;
    while(it != v.end() && K){
        answer -= *it;
        K--, it++;
    }
    cout << answer;
}