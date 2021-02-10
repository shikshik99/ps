#include <string>
#include <map>
#include <vector>

using namespace std;

map <string, int> m;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string str;
    for(int i = 0; i < phone_book.size(); i++) m[phone_book[i]] = 1;
    for(int i = 0; i < phone_book.size(); i++){
        str = "";
        for(int j = 0; j < phone_book[i].length(); j++){
            str += phone_book[i][j];
            if(j == phone_book[i].length() - 1) break;
            if(m.count(str)) return false;
        }
    }
    return answer;
}