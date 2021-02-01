#include <string>
#include <cstring>
#include <vector>

using namespace std;

int arr[1001][1001] = {0};

vector<int> solution(int n) {
    memset(arr, 0, sizeof(arr));
    vector<int> answer;
    int state = 0, x = 0, y = 0, num = 1, ma = 0;
    
    for(int i = n; i>0; i--) ma += i;
    
    while(num <= ma){
        if(state == 0){
            while(x < n){
                if(arr[x][y] != 0) {x--; y++; break;}
                arr[x][y] = num; num++;
                x++;
            }
            if(x>=n){x--; y++;}
        }
        else if(state == 1){
            while(y <= x){
                if(arr[x][y] != 0){x--; y-=2; break;}
                arr[x][y] = num; num++;
                y++;
            }
            if(y>x) {x--;y-=2;}
        } 
        else if(state == 2){
            while(x>=0){
                if(arr[x][y] != 0){x+=2; y++; break;}
                arr[x][y] = num; num++;
                x--; y--;
            }
            if(x < 0) {x+=2; y++; break;}
        }
        state = (state+1)%3;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++) answer.push_back(arr[i][j]);
    }
    
    return answer;
}