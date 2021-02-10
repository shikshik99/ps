#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string tmp, str = "";
int arr[27];

int main(){
    memset(arr, 0, sizeof(arr));
    int i = 0, ma = 0;
    for(i = 0; i < 5000 && !cin.eof(); i++)getline(cin,tmp), str +=tmp;
    for(i = 0; i < str.length(); i++) if(str[i] != ' ' && str[i] != '\n')arr[str[i]-'a']++;
    for(i = 0; i < 28; i++) if(arr[i] > ma) ma = arr[i];
    for(i = 0; i < 28; i++) if(arr[i] == ma) cout << (char)(i + 'a');
}