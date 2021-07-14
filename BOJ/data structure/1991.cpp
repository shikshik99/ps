#include <iostream>
#include <vector>
using namespace std;

struct Tree{
    char ch;
    Tree *left = NULL;
    Tree *right = NULL;
};

vector <Tree> v;

void preorder(Tree *tmp){
    cout << tmp->ch;
    if(tmp->left != NULL) preorder(tmp->left);
    if(tmp->right != NULL) preorder(tmp->right);
}

void inorder(Tree *tmp){
    if(tmp->left != NULL) inorder(tmp->left);
    cout << tmp->ch;
    if(tmp->right != NULL) inorder(tmp->right);
}

void postorder(Tree *tmp){
    if(tmp->left != NULL) postorder(tmp->left);
    if(tmp->right != NULL) postorder(tmp->right);
    cout << tmp->ch;
}

int main(){
    int N;
    char node, l, r;
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> node >> l >> r;
        v[node - 'A'].ch = node;
        if(l != '.') v[node - 'A'].left = &v[l - 'A'];
        if(r != '.') v[node - 'A'].right = &v[r - 'A'];
    }
    preorder(&v[0]), cout << '\n';
    inorder(&v[0]), cout << '\n';
    postorder(&v[0]), cout << '\n';
    
}