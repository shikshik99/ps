#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[500][500];

int solution(vector<vector<int>> triangle) {
    memset(arr, 0, sizeof(arr));
    for(int i = triangle.size() - 1; i >= 0; i--){
        for(int j = 0; j < triangle[i].size(); j++){
            if(i == triangle.size() - 1) arr[i][j] = triangle[i][j];
            else{
                arr[i][j] = max(triangle[i][j] + arr[i+1][j], triangle[i][j] + arr[i+1][j+1]);
            }
        }
    }
    return arr[0][0];
}