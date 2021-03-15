#include <iostream>
#include <string>
using namespace std;

int arr[100][4];

int main(){
    int cnt = 0;
    string str;
    getline(cin, str);
    while(!cin.eof()){
        for(int i = 0; i < str.length(); i++){
            if(str[i] >= 97 && str[i] <= 97+26) arr[cnt][0]++;
            else if(str[i] >= 65 && str[i] <= 65+26) arr[cnt][1]++;
            else if(str[i] >= 48 && str[i] <= 48 + 10) arr[cnt][2]++;
            else if(str[i] == ' ') arr[cnt][3]++;
        }
        cnt++;
        getline(cin, str);
    }
    for(int i = 0; i < cnt; i++) cout << arr[i][0] << ' ' << arr[i][1] << ' ' << arr[i][2] << ' ' << arr[i][3] << '\n';
}