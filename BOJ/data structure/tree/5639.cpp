#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct node{
    int num;
    node *left = NULL;
    node *right = NULL;
};

void make_tree(node *tmp, int num){
    if(tmp->num > num){
        if(tmp->left == NULL) {
            node *l = new node;
            tmp->left = l;
            l->num = num;
        }
        else make_tree(tmp->left, num);
    }
    else{
        if(tmp->right == NULL) {
            node *r = new node;
            tmp->right = r;
            r->num = num ;   
        }
        else make_tree(tmp->right, num);
    }
}

void preorder(node *tmp){
    if(tmp == NULL) return;
    preorder(tmp->left);
    preorder(tmp->right);
    cout << tmp->num << '\n';
}

int main(){
    int a;
    cin >> a;
    node *tmp = new node;
    tmp->num = a;
    while(cin >> a) make_tree(tmp, a);

    preorder(tmp);
}