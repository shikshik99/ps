#include <iostream>
using namespace std;

struct node{
    node *prev = NULL;
    node *next = NULL;
    int num;
};

node *head = NULL, *tail = NULL;
int N, K;

void insert(int num){
    node *tmp = new node;
    tmp->num = num;
    if(head == NULL){
        head = tmp;
        tail = tmp;
        return;
    }
    
    head->prev = tmp;
    tmp->prev = tail;
    tmp->next = head;
    tail->next = tmp;
    tail = tmp;
}

int erase(int idx){
    node *tmp = head;
    while(idx--) tmp = tmp->next;
    int ret = tmp->num;
    
    head = tmp->next;
    if(head == NULL) return ret;
    head->prev = tmp->prev;
    tmp->prev->next = head;
    
    delete tmp;
    return ret;
}

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++) insert(i);

    cout << '<';
    for(int i = 0; i < N; i++){
        if(i == N - 1) cout << erase(K - 1);
        else cout << erase(K - 1) << ", ";
    }
    cout << '>';
}