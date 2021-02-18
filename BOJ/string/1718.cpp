#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b;
    getline(cin, a), getline(cin ,b);
    for(int i = 0; i < a.length(); i++){
        if(a[i] == ' ') continue;
        a[i] = a[i] - b[i%b.length()] - 1;
        if(a[i] < 0) a[i] +=26;
        a[i] += 'a';
    }
    cout << a;
}