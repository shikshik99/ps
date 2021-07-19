#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[51] = {0,};
int bit = 0, N, K;

int DFS(int idx, int depth){
    int answer = 0;
    if(depth == K){
        for(int i = 0; i < N; i++){
            if((arr[i] & bit) == arr[i]) answer++;
        }

        return answer;
    }

    for(int i = idx; i < 26; i++){
        if(bit & (1 << i)) continue;
        bit |= (1 << i);
        answer = max(answer, DFS(i + 1, depth + 1));
        bit &= ~(1 << i);
    }

    return answer;
}

int main(){
    cin >> N >> K;

    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        int len = str.length();
        for(int j = 0; j < len; j++){
            arr[i] |= 1 << (str[j] - 'a');
        }
    }

    if(K < 5) cout << 0 << '\n', exit(0);
    K -= 5;

    bit |= (1 << ('a' - 'a'));
    bit |= (1 << ('n' - 'a'));
    bit |= (1 << ('t' - 'a'));
    bit |= (1 << ('i' - 'a'));
    bit |= (1 << ('c' - 'a'));

    cout << DFS(0, 0);
}