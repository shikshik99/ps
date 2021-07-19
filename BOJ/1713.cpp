#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector <pii> frame;
vector <int> student;
int N, M;

void foo(){
    for(int i = 0; i < N; i++) frame[i].second++;
}

bool blank(int idx){
    for(int i = 0; i < N; i++){
        if(frame[i].first == -1){
            frame[i].first = idx, frame[i].second = 0;
            foo();
            return true;
        }
    }

    return false;
}

bool chk_exist(int idx){
    for(int i = 0; i < N; i++){
        if(frame[i].first == idx) {
            foo();
            return true;
        }
    }

    return false;
}

void recommend(int idx){
    pii tmp = frame[0];
    int ii = 0;
    for(int i = 1; i < N; i++){
        if(student[frame[i].first] < student[tmp.first]) tmp = frame[i], ii = i;
        else if(student[frame[i].first] == student[tmp.first]){
            if(frame[i].second > tmp.second) tmp = frame[i], ii = i;
        }
    }

    student[tmp.first] = 0;
    frame[ii].first = idx, frame[ii].second = 0;
}

bool cmp(pii a, pii b){
    return a.first < b.first ? true : false;
}

int main(){
    cin >> N >> M;
    student.resize(101, 0);
    frame.resize(N);
    for(int i = 0; i < N; i++) frame[i].first = -1;

    int tmp;
    for(int i = 0; i < M; i++){
        cin >> tmp;
        student[tmp]++;
        if(chk_exist(tmp)) continue;
        if(blank(tmp)) continue;
        recommend(tmp);
        foo();
    }

    sort(frame.begin(), frame.end(), cmp);
    for(auto it : frame) cout << it.first << ' ';
    cout << '\n';
}