#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int arr[21];
int tar, N;

int DFS(int depth, int num){
    if(depth >= N){
        if(num == tar) return 1;
        return 0;
    }
    
    int ret = 0;
    ret += DFS(depth + 1, num + arr[depth]);
    ret += DFS(depth + 1, num - arr[depth]);
    
    return ret;
}

int solution(vector<int> numbers, int target) {
    tar = target, N = numbers.size();
    
    for(int i = 0; i < N; i++) arr[i] = numbers[i];
    
    return DFS(0, 0);
}