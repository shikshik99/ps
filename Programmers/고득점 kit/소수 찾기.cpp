#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

bool chk[100000001];
int arr[10];

int foo(int num){
    int tmp[10];
    int ans = 0;
    for(int i = 2; i * i <= num; i++){
        if (chk[i]) continue;
        for(int j = i * i; j <= num; j += i){
            chk[j] = true;
        }
    }
    int a;
    for(int i = 2; i <= num ; i++){
        if(!chk[i]){
            memset(tmp, 0, sizeof(tmp));
            a = i;
            while(a > 0){
                tmp[a%10]++;
                a /= 10;
            }
            for(int j = 0; j < 10; j++){
                if(tmp[j] > arr[j]) {ans--; break;}
            }
            ans++;
        }
    }
    return ans;
}

int solution(string numbers) {
    int answer = 0, tmp = 0;
    vector <int>v;
    memset(chk, false, sizeof(chk));
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < numbers.size(); i++) v.push_back(numbers[i] - '0');
    sort(v.begin(), v.end(), greater<>());
    for(auto it : v) tmp = tmp * 10 + it, arr[it]++;
    answer = foo(tmp);
    return answer;
}