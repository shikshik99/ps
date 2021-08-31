#include <iostream>
#define MAX 100001
using namespace std;

int pq[MAX] = {0, };
int sizz = 0, top = 1;

void pop(){
    if(!sizz){
        cout << 0 << '\n'; return;
    }

    cout << pq[top] << '\n';
    pq[top] = pq[sizz];
    pq[sizz--] = 0x6f6f6f6f;
    int parent = top, child = (pq[2] < pq[3] ? 2 : 3);
    while(parent * 2 <= sizz && pq[parent] > pq[child]){
        swap(pq[parent], pq[child]);
        parent = child;
        int left = parent * 2, right = parent * 2 + 1;
        child = (pq[left] < pq[right] ? left : right);
    }
}

void push(int num){
    sizz++;
    pq[sizz] = num;
    int parent = sizz / 2, child = sizz;
    while(parent && pq[parent] > pq[child]){
        swap(pq[parent], pq[child]);
        child = parent;
        parent = child / 2;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, num;
    cin >> N;
    while(N--){
        cin >> num;
        if(!num) pop();
        else push(num);
    }
}