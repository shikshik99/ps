#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
using pis = pair<int, string>;

vector <pis> D[MAX];
string A, B;
pis ans;

int main(){
    for(int i = 0; i < MAX; i++) D[i].resize(MAX, {0, ""});
    cin >> A >> B;
    for(int i = 1; i <= A.length(); i++){
        for(int j = 1; j <= B.length(); j++){
            if(A[i - 1] == B[j - 1]){
                D[i][j].first = D[i-1][j-1].first + 1;
                D[i][j].second =D[i-1][j-1].second + A[i - 1];
            }
            else {
                if(D[i-1][j].first < D[i][j - 1].first) D[i][j] = D[i][j - 1];
                else D[i][j] = D[i - 1][j];
            }
            ans = D[i][j];
        }
    }
    cout << ans.first << '\n' << ans.second << '\n';
}