#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set <int> s;

int main(){
    int a, b, tmp;
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> tmp;
        s.insert(tmp);
    }
    for(int i = 0; i < b; i++){
        cin >> tmp;
        if(s.count(tmp)) s.erase(tmp);
        else s.insert(tmp);
    }

    cout << s.size();
}