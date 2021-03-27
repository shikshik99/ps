#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> A, B;
int cntA = 0, cntB = 0, answer = 0;

void Awin(){
    answer = max(answer, cntB), cntB = 0, cntA++;
}

void Bwin() {
    answer = max(answer, cntA), cntA = 0, cntB++;
}

int main(){
    int N;
    cin >> N, A.resize(N), B.resize(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++){
        if(A[i] == 1){
            if(B[i] == 1){
                if(cntA > cntB) Bwin(); else Awin();
            }
            else if(B[i] == 2) Bwin();
            else if(B[i] == 3) Awin();
        }
        else if(A[i] == 2){
            if(B[i] == 1) Awin();
            else if(B[i] == 2){
                if(cntA > cntB) Bwin(); else Awin();
            }
            else if(B[i] == 3) Bwin();
        }
        else if(A[i] == 3){
            if(B[i] == 1) Bwin();
            else if(B[i] == 2) Awin();
            else if(B[i] == 3){
                if(cntA > cntB) Bwin(); else Awin();
            }
        }
    }
    answer = max({answer, cntA, cntB});
    cout << answer;
}