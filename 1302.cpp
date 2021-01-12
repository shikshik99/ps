#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string, int> m;
map <string, int>::iterator iter, ans;

int main(){
    string book;
    int N, tmp;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> book;
        if(m.count(book)){
            tmp = m[book];
            m[book] = tmp + 1;
        } 
        else{
            m.insert(make_pair(book, 1));
        }
    }
    tmp = 0;
    for(iter = m.begin(); iter != m.end(); iter++){
        if(iter->second > tmp) {tmp = iter->second; ans = iter;}
    }
    cout << ans->first;
}