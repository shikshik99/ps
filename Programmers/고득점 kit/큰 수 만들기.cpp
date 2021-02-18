#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int i = 0;
    auto it = number.begin();
    auto it2 = number.begin(); it2++;
    while(i < k){
        if(*it < *it2 || it2 == number.end()){
            number.erase(it);
            it = number.begin();
            it2 = number.begin(); it2++;
            i++;
        }
        else it++, it2++;
    }
    return number;
}