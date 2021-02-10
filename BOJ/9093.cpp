#include <iostream>
#include <string>
using namespace std;

int N;
string str[1000001];

void foo(){
    for(int i = 0; i < N; i++){
        int pivot = -1;
        for(int j = 0; j < str[i].length()+1; j++){
            if(str[i][j] == ' '|| j == str[i].length()){
                int tmp = j - 1;
                while(tmp != pivot){cout<<str[i][tmp]; tmp--;}
                cout << ' ';
                pivot = j;
            }
        }
        cout << '\n';
    }
}

int main(){
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) getline(cin, str[i]);
    foo();
}