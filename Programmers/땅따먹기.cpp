#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[100001][4];

int solution(vector<vector<int>> land)
{
    memset(arr, 0, sizeof(arr));
    int answer = 0;
    for(int i = 0; i < 4; i++) arr[0][i] = land[0][i];
    for(int i = 1; i < land.size(); i++){
        for(int j = 0; j < 4; j++){
            if(j == 0)arr[i][j] = land[i][j] + max({arr[i-1][1], arr[i-1][2], arr[i-1][3]});
            if(j == 1)arr[i][j] = land[i][j] + max({arr[i-1][0], arr[i-1][2], arr[i-1][3]});
            if(j == 2)arr[i][j] = land[i][j] + max({arr[i-1][0], arr[i-1][1], arr[i-1][3]});
            if(j == 3)arr[i][j] = land[i][j] + max({arr[i-1][1], arr[i-1][2], arr[i-1][0]});
        }
    }
    return answer = max({arr[land.size() - 1][0], arr[land.size() - 1][1], arr[land.size() - 1][2], arr[land.size() - 1][3]});
}