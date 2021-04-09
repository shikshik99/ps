#include <iostream>
#include <string>
using namespace std;

int main(){
    string cmp;
    int A, B, idx = 1;
    while(1){
        cin >> A >> cmp >> B;
        if(cmp == ">"){
            if(A > B) cout << "Case " << idx << ": true";
            else cout << "Case " << idx << ": false";
        }
        else if(cmp == ">="){
            if(A >= B) cout  << "Case " << idx << ": true";
            else cout << "Case " << idx << ": false";
        }
        else if(cmp == "<"){
            if(A < B) cout << "Case " << idx << ": true";
            else cout << "Case " << idx << ": false";
        }
        else if(cmp == "<="){
            if(A <= B) cout << "Case " << idx << ": true";
            else cout << "Case " << idx << ": false";
        }
        else if(cmp == "=="){
            if(A == B) cout << "Case " << idx << ": true";
            else cout << "Case " << idx << ": false";
        }
        else if(cmp == "!="){
            if(A != B) cout << "Case " << idx << ": true";
            else cout << "Case " << idx << ": false";
        }
        else if(cmp == "E"){
            return 0;
        }
        cout << '\n';
        idx++;
    }
}