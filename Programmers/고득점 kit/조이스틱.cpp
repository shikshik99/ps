#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0, l = 0, r = 0, lr = 0, rl = 0, pivot = 0, lpivot = 0, rpivot = 0;
    for(int i = 0 ; i < name.size(); i++){
        if(name[i] <= 'N') answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;
        if(name[i] != 'A') {
            if(i < name.size() / 2) r += i - pivot, lr += i - pivot, rl += i - pivot, rpivot = pivot = i;
            else r += i - pivot, pivot = i;
        }
    }
    pivot = name.size();
    for(int i = name.size() - 1; i >= 1; i--){
        if(name[i] != 'A') {
            if(i >= name.size() / 2) l += pivot - i, lr += pivot - i, rl += pivot - i, lpivot = pivot = i;
            else l += pivot - i, pivot = i;
        }
    }
    if(lpivot != 0)lr += name.size() - lpivot;
    else lr = 0x7f7f7f7f;
    if(rpivot != 0)rl += rpivot;
    else rl = 0x7f7f7f7f;
    return answer + min(l, min(rl, min(r, lr)));
}