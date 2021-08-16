#include <iostream>
#include <list>
#include <string>
using namespace std;

list <char> l;

void foo(string str){
    auto it = l.begin();
    for(auto x : str){
        if(x == '<'){
            if(it != l.begin()) it--;
        }
        else if(x == '>'){
            if(it != l.end()) it++;
        }
        else if(x == '-'){
            if(it != l.begin()){
                it--; it = l.erase(it);
            }
        }
        else{
            l.insert(it, x);
        }
    }

    for(auto it : l) cout << it;
    cout << '\n';
}

int main(){
    int T;
    string str;
    cin >> T;
    while(T--){
        l.clear();
        cin >> str;
        foo(str);
    }
}