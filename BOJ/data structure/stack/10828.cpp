#include <iostream>
#include <string>
using namespace std;

struct node{
    node *left = NULL;
    node *right = NULL;
    int num;
    node(node *l, node *r, int tmp) : left{l}, right{r}, num{tmp} {}
};

node *tail = NULL;
int cnt = 0;

void push(int num){
    if(tail == NULL) tail = new node(NULL, NULL, num);
    else {
        node *tmp = new node(tail, NULL, num);
        tail->right = tmp;
        tail = tmp;
    }

    cnt++;
}

void pop(){
    if(!cnt){
        cout << -1 << '\n'; return;
    }
    node *tmp = tail;
    tail = tail->left;
    cout << tmp->num << '\n';
    
    delete tmp;
    cnt--;
}

void size(){
    cout << cnt << '\n';
}

void empty(){
    cout << (!cnt ? 1 : 0) << '\n';
}

void top(){
    if(!cnt) cout << -1 << '\n';
    else cout << tail->num << '\n';
}

int main(){
    int N;
    cin >> N;

    string cmd;
    int num;
    while(N--){
        cin >> cmd;
        if(cmd == "push") cin >> num, push(num);
        else if(cmd == "pop") pop();
        else if(cmd == "size") size();
        else if(cmd == "empty") empty();
        else if(cmd == "top") top();
    }
}