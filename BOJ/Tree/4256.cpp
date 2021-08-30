#include <iostream>
#define MAX 1001
using namespace std;

int preorder[MAX], inorder[MAX], inpos[MAX];
int pos;

void postorder(int start, int end){
    if(start == end) return;
    int root = preorder[pos++];
    int mid = inpos[root];
    postorder(start, mid);
    postorder(mid + 1, end);
    cout << root << ' ';
}

int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        pos = 0;
        for(int i = 0; i < N; i++) cin >> preorder[i];
        for(int i = 0; i < N; i++) cin >> inorder[i], inpos[inorder[i]] = i;
        postorder(0, N);
        cout << '\n';
    }
}