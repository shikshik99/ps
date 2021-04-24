#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int main(){
    int a, b, tmp;
    cin >> a >> b;
    tmp = a;
    while(1){
        if(v.empty()){
            v.push_back(tmp);
            tmp *= a;
            tmp %= b;
        }
        else{
            for(int i = 0; i < v.size(); i++){
                if(v[i] == tmp) {
                    cout << v.size() - i; return 0;
                }
            }
            v.push_back(tmp), tmp*= a, tmp%= b;
        }
    }
}