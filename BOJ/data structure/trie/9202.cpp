#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Node{
    Node *arr[26] = {NULL, };
    bool isEnd = false;
};

char boggle[4][4];
bool chk[4][4];
int dir[8][2] = {{-1, -1}, {1, -1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int N, w, answer, cnt, max_len;
string longest;
set <string> s;
Node *root;

void make_trie(string str){
    Node *tmp = root;
    int len = str.length();
    for (int i = 0; i < len; i++){
        int num = str[i] - 'A';
        if (tmp->arr[num] == NULL) {
            tmp->arr[num] = new Node;
        }
        tmp = tmp->arr[num];
    }
    tmp->isEnd = true;
}

void get_boggle(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> boggle[i][j];
        }
    }
}

void CLEAR(){
    memset(chk, false, sizeof(chk));
    memset(boggle, 0, sizeof(boggle));
    answer = 0, cnt = 0, max_len = 0;
    longest.clear();
    s.clear();
}

void DFS(Node *tmp, int x, int y, int depth, string str){
    if(str.length() > 8) return;
    if(tmp == NULL || chk[x][y]) return;
    auto it = s.find(str);
    if(tmp->isEnd && it == s.end()){
        s.insert(str);
        cnt++;
        answer += score[depth];
        if(depth > max_len) {
            max_len = depth;
            longest = str;
        }
        else if(depth == max_len){
            longest = longest < str ? longest : str;
        }
    }
    chk[x][y] = true;
    for(int i = 0; i < 8; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx < 0 || dx >= 4 || dy < 0 || dy >= 4 || chk[dx][dy]) continue;
        char ch = boggle[dx][dy];
        if(tmp->arr[ch - 'A'] != NULL) {
            str += ch;
            DFS(tmp->arr[ch - 'A'], dx, dy, depth + 1, str);
            str.pop_back();
        }
    }
    chk[x][y] = false;
}

void play_boggle(){
    string str = "";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int num = (boggle[i][j] - 'A');
            if(root->arr[num] != NULL){
                str += boggle[i][j];
                DFS(root->arr[num], i, j, 1, str);
                str.clear();
            }
        }
    }
    cout << answer << ' ' << longest << ' ' << cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    root = new Node;
    cin >> N;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        make_trie(str);
    }
    cin >> w;
    while(w--){
        CLEAR();
        get_boggle();
        play_boggle();   
    }
}