#include <iostream>
using namespace std;

struct Node{
    struct Node *prev = NULL;
    struct Node *next = NULL;
    int num;
};

struct Node *head = NULL, *tail = NULL;

void insert(int num){
    struct Node *tmp = new Node;
    tmp->num = num;
    if(head == NULL){
        head = tmp;
        tail = head;
        return;
    }

    tail->next = tmp;
    tmp->prev = tail;
    tmp->next = head;
    head->prev = tmp;
    tail = tmp;
}

int erase(int num){
    if(head->num == num){
        struct Node *tmp = head;
        head = head->next;
        if(head == NULL) return 0;
        tmp->prev->next = head;
        head->prev = tmp->prev;
        delete tmp;
        return 0;
    }
    
    struct Node *ltmp = head, *rtmp = head;
    int lcnt = 0, rcnt = 0;
    while(ltmp->num != num) lcnt++, ltmp = ltmp->prev;
    while(rtmp->num != num) rcnt++, rtmp = rtmp->next;

    
    head = rtmp->next;
    rtmp->prev->next = head;
    head->prev = rtmp->prev;

    delete rtmp;
    return lcnt < rcnt ? lcnt : rcnt;
}

int N, M;

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) insert(i);

    int tmp, answer = 0;
    for(int i = 0; i < M; i++){
        cin >> tmp;
        answer += erase(tmp);
    }

    cout << answer << '\n';
}