#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[4][3][3][3];
vector<string> s;

vector<string> split(string str){
    string tmp;
    vector <string> ret;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ' && tmp != "and") ret.push_back(tmp), tmp.clear();
        else if(str[i] == ' ' && tmp == "and") tmp.clear();
        else tmp += str[i];
    }
    ret.push_back(tmp);
    
    return ret;
}

int classi(int idx, string str){
    if(idx == 0){
        if(str == "cpp") return 1;
        else if(str == "java") return 2;
        else if(str == "python") return 3;
        else return 0;
    }
    else if(idx == 1){
        if(str == "backend") return 1;
        else if(str == "frontend") return 2;
        else return 0;
    }
    else if(idx == 2){
        if(str == "junior") return 1;
        else if(str == "senior") return 2;
        else return 0;
    }
    else if(idx == 3) {
        if(str == "chicken") return 1;
        else if(str == "pizza") return 2;
        else return 0;
    }
}

void ins(int a, int b, int c, int d, int num){
    v[a][b][c][d].push_back(num);
    v[a][b][c][0].push_back(num);
    v[a][b][0][d].push_back(num);
    v[a][b][0][0].push_back(num);
    v[a][0][c][d].push_back(num);
    v[a][0][c][0].push_back(num);
    v[a][0][0][d].push_back(num);
    v[a][0][0][0].push_back(num);
    v[0][b][c][d].push_back(num);
    v[0][b][c][0].push_back(num);
    v[0][b][0][d].push_back(num);
    v[0][b][0][0].push_back(num);
    v[0][0][c][d].push_back(num);
    v[0][0][c][0].push_back(num);
    v[0][0][0][d].push_back(num);
    v[0][0][0][0].push_back(num);
}


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i = 0; i < info.size(); i++){
        s.clear();
        s = split(info[i]);
        ins(classi(0, s[0]), classi(1, s[1]), classi(2, s[2]), classi(3, s[3]), stoi(s[4]));
    }
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                for(int a = 0; a < 3; a++){
                    sort(v[i][j][k][a].begin(), v[i][j][k][a].end());
                }   
            }
        }
    }
    
    for(int i = 0; i < query.size(); i++){
        s.clear();
        s = split(query[i]);
        int num = stoi(s[4]);
        int a, b, c, d;
        a = classi(0, s[0]), b = classi(1, s[1]), c = classi(2, s[2]), d = classi(3, s[3]);
        for(int j = 0; j < v[a][b][c][d].size(); j++){
            if(v[a][b][c][d][j] >= num) {answer.push_back(v[a][b][c][d].size() - j); break;}
        }
        if(i >= answer.size()) answer.push_back(0);
    }
    
    return answer;
}