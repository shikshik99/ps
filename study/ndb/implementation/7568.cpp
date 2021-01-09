#include <iostream>
#include <vector>
using namespace std;

vector <pair<int,int>> v;
int foo[51];
int foo1[51] = {0};

int main(){
    fill_n(foo, 51, 1);
    int a, b, N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>> a >> b;
        v.push_back(make_pair(a,b));
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j < N; j++){
            if(v[i].first<v[j].first && v[i].second<v[j].second) foo[i] += 1;
        }
        cout << foo[i] << ' ';
    }
}