#include <iostream>
#include <string>
using namespace std;

template <typename T>
class node{
    public :
    node <T> *left;
    node <T> *right;
    T val;
    node() : right(NULL), left(NULL), val() {}
    node(node <T> *l, node <T> *r, T value) : right(r), left(l), val(value) {}
};

template <typename T>
class deque{
    public :
    node <T> *head;
    node <T> *rear;
    int sizz;
    
    deque() : head(NULL), rear(NULL), sizz(0) {}

    void push_front(T value){
        sizz++;
        if(sizz == 1){
            node <T> *tmp = new node<T>(NULL, NULL, value);
            head = tmp;
            rear = tmp;
            return;
        }
        node <T> *tmp = new node<T>(head, NULL, value);
        head->right = tmp;
        head = tmp;
    }

    void push_back(T value){
        sizz++;
        if(sizz == 1){
            node <T> *tmp = new node<T>(NULL, NULL, value);
            head = tmp;
            rear = tmp;
            return;
        }

        node <T> *tmp = new node<T>(NULL, rear, value);
        rear->left = tmp;
        rear = tmp;
    }

    void pop_front(){
        if(!sizz){
            cout << -1 << '\n';
            return;
        }

        sizz--;
        node <T> *tmp = head;
        head = head->left;
        cout << tmp->val << '\n';
        delete tmp;
    }

    void pop_back(){
        if(!sizz){
            cout << -1 << '\n';
            return;
        }

        sizz--;
        node <T> *tmp = rear;
        rear = rear->right;
        cout << tmp->val << '\n';
        delete tmp;
    }

    void size(){
        cout << sizz << '\n';
    }

    void empty(){
        if(!sizz) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    void front(){
        if(!sizz) cout << -1 << '\n';
        else cout << head->val << '\n';
    }
    
    void back(){
        if(!sizz) cout << -1 << '\n';
        else cout << rear->val << '\n';
    }
};

deque <int> dq;

int main(){
    int N;
    cin >> N;
    string str;
    int num;
    while(N--){
        cin >> str;
        if(str == "push_front") cin >> num, dq.push_front(num);
        else if(str == "push_back") cin >> num, dq.push_back(num);
        else if(str == "pop_front") dq.pop_front();
        else if(str == "pop_back") dq.pop_back();
        else if(str == "size") dq.size();
        else if(str == "empty") dq.empty();
        else if(str == "front") dq.front();
        else if(str == "back") dq.back();
    }
}