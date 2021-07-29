#include <iostream>
#include <cstring>
using namespace std;

int tree[26][2];

void preorder(int idx){
    if(idx == -1) return;
    cout << (char)(idx + 'A');
    preorder(tree[idx][0]);
    preorder(tree[idx][1]);
}

void inorder(int idx){
    if(idx == -1) return;
    inorder(tree[idx][0]);
    cout << (char)(idx + 'A');
    inorder(tree[idx][1]);
}

void postorder(int idx){
    if(idx == -1) return;
    postorder(tree[idx][0]);
    postorder(tree[idx][1]);
    cout << (char)(idx + 'A');
}

int main(){
    memset(tree, -1, sizeof(tree));
    int N;
    char ch, l, r;

    cin >> N;
    while(N--){
        cin >> ch >> l >> r;
        if(l != '.') tree[ch - 'A'][0] = (l - 'A');
        if(r != '.') tree[ch - 'A'][1] = (r - 'A');
    }
    preorder(0), cout << '\n';
    inorder(0), cout << '\n';
    postorder(0), cout << '\n';
}