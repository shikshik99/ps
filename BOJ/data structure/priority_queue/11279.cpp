#include <iostream>
#define MAX 100001
using namespace std;

int pq[MAX] = {0, };
int N, sizz = 0;

void push(int num){
    sizz++;
    pq[sizz] = num;
    int parent = sizz / 2, child = sizz;
    while(parent && pq[parent] < pq[child]){
        swap(pq[parent], pq[child]);
        child = parent;
        parent = child / 2;
    }
}

void pop(){
    if(!sizz) {
        cout << 0 << '\n';
        return ;
    }
    
    cout << pq[1] << '\n';
    int parent = 1, child = (pq[2] > pq[3] ? 2 : 3);
    pq[1] = pq[sizz];
    pq[sizz--] = 0;
    while(parent * 2 <= sizz && pq[parent] < pq[child]){
        swap(pq[parent], pq[child]);
        parent = child;
        int left = parent * 2, right = parent * 2 + 1;
        child = (pq[left] > pq[right] ? left : right);
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    int num;
    while(N--){
        cin >> num;
        if(!num) pop();
        else push(num);
    }
}