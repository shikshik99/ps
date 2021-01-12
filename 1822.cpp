#include <iostream>
#include <set>
using namespace std;

set <int>s;
set <int>::iterator it;

int main (){
    int a, b, tmp;
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> tmp;
        s.insert(tmp);
    }
    for(int i = 0; i < b; i++){
        cin >> tmp;
        if(s.count(tmp)) s.erase(tmp);
    }
    if(s.empty()) {cout << 0; return 0;}
    cout << s.size() << '\n';
    for(it = s.begin(); it != s.end(); it++) cout << *it << ' ';
}