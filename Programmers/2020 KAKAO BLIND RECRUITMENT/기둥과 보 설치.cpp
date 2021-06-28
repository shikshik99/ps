#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[102][102] = {0,};
int N;

bool compare(vector<int> a, vector<int> b){
    if(a[0] != b[0]) return a[0] < b[0] ? true : false;
    else {
        if(a[1] != b[1]) return a[1] < b[1] ? true : false;
        else return a[2] < b[2] ? true : false;
    }
}

bool check_pillar(int i, int j){
    if(i == N - 1) return true;
    else{
        if(i < N - 1 && (arr[i + 1][j] == 1 || arr[i+1][j] == 3)) return true;
        else if(j > 0 && arr[i][j - 1] >= 2) return true;
        else if(arr[i][j] >= 2) return true;
    }
    return false;
}

bool check_roof(int i, int j){
    if(i < N - 1 && (arr[i + 1][j] == 1 || arr[i + 1][j] == 3)) return true;
    else if(i < N - 1 && j < N - 1 && (arr[i + 1][j + 1] == 1 || arr[i + 1][j + 1] == 3)) return true;
    else if(j > 0 && j < N - 1 && arr[i][j - 1] >= 2 && arr[i][j + 1] >= 2) return true;
    return false;
}

void build_structure(int x, int y, int a){
    // cout << x << ' ' <<  y << ' ' << a << '\n';
    if(!a){
        if(check_pillar(x,y)) arr[x][y] += 1;
    }
    else{
        if(check_roof(x,y)) arr[x][y] += 2;
    }
}

bool check_board(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == 1){ // 기둥
                if(!check_pillar(i, j)) return false;
            }
            else if(arr[i][j] == 2){
                if(!check_roof(i, j)) return false;
            }
            else if(arr[i][j] == 3){
                if(!check_pillar(i, j)) return false;
                if(!check_roof(i, j)) return false;
            }
        }
    }
    return true;
}

void del_structure(int x, int y, int a){
    arr[x][y] -= (a + 1);
    if(check_board()) return;
    else arr[x][y] += a + 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int x, y, a, b;
    n++;
    N = n;
    
    for(int i = 0; i < build_frame.size(); i++){
        x = build_frame[i][0], y = build_frame[i][1], a = build_frame[i][2], b = build_frame[i][3];
        if(!b) del_structure(n - y - 1, x, a);
        else build_structure(n - y - 1, x, a);
    }   
    
    vector <int> tmp;
    tmp.resize(3);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
            if(arr[i][j] == 1 || arr[i][j] == 2){
                tmp[0] = j;
                tmp[1] = abs(i - n + 1);
                tmp[2] = arr[i][j] - 1;
                answer.push_back(tmp);
            }
            if(arr[i][j] == 3){
                tmp[0] = j;
                tmp[1] = abs(i - n + 1);
                tmp[2] = 0;
                answer.push_back(tmp);
                tmp[2] = 1;
                answer.push_back(tmp);
            }
        }
        cout << '\n';
    }
    sort(answer.begin(), answer.end(), compare);
    // for(int i = 0; i < answer.size(); i++){
    //     for(int j = 0; j < 3; j++) cout << answer[i][j] << ' ';
    //     cout << '\n';
    // }
    return answer;
}