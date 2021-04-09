#include <iostream>
#include <string>
using namespace std;

bool find_nemo(string str){
    if((str[0] == 'n' || str[0] == 'N') && (str[1] == 'e' || str[1] == 'E') && (str[2] == 'm' || str[2] == 'M') && (str[3] == 'o' || str[3] == 'O')) return true;
    return false;
}

int main(){
    string str, tmp;
    char a= 'a', b= 'A';
    bool flag = false;
    while(1){
        getline(cin, str);
        if(str == "EOI") return 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ' ' || i == str.length() - 1) flag = find_nemo(tmp), tmp.clear();
            else if ((str[i] >= 97 && str[i] < 97 + 26) || (str[i] >= 65 && str[i] < 65 + 26)) tmp += str[i];
            if(flag) break;
        }  
        if(flag) cout << "Found\n";
        else cout << "Missing\n";
        flag = false;
    }
}