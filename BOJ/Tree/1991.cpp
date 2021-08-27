#include <iostream>
#include <vector>
using namespace std;

vector <vector<char>> tree;
int N;

void pre(int idx){
    cout << char(idx + 'A');
    for(char it : tree[idx]){
        if(it == '.') continue;
        pre(it - 'A');
    }
}

void in(int idx){
    char l = tree[idx][0], r = tree[idx][1];
    if(l != '.') in(l - 'A');    
    cout << char(idx + 'A');
    if(r != '.') in(r - 'A');    
}

void post(int idx){
    for(char it : tree[idx]){
        if(it == '.') continue;
        post(it - 'A');
    }
    cout << char(idx + 'A');
}

int main(){
    cin >> N;
    tree.resize(N);
    char node, l, r;
    for(int i = 0; i < N; i++) {
        cin >> node >> l >> r;
        tree[node - 'A'].push_back(l), tree[node - 'A'].push_back(r);
    }

    pre(0);
    cout << '\n';
    in(0);
    cout << '\n';
    post(0);
    cout << '\n';
}