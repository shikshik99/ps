#include <iostream>
#include <string>
using namespace std;

template <typename T>
class node{
    public :
    node <T> *right;
    node <T> *left; 
    T value;

    node <T>() : right(NULL), left(NULL){}
    node <T>(node <T> *r, node <T> *l, T val) : right(r), left(l), value(val){}
};

template <typename T>
class queue{
    public :
    node <T> *head;
    node <T> *rear;
    int sizz;

    queue <T>() : head(NULL), rear(NULL), sizz(0){}

    public :
    void push(T val){
        sizz++;
        if(sizz == 1){
            node <T> *tmp = new node <T>(NULL, NULL, val);
            head = tmp;
            rear = tmp;
            return ;
        }
        node <T> *tmp = new node <T>(NULL, rear, val);
        rear->left = tmp;
        rear = tmp;
    }

    void pop(){
        if(sizz == 0) {
            cout << -1 << '\n';
            return;
        }
        sizz--;
        node <T> *tmp = head;
        head = head->left;
        cout << tmp->value << '\n';
        delete tmp;
    }

    void size(){
        cout << sizz << '\n';
    }

    void empty(){
        if(!sizz) cout << 1 <<'\n';
        else cout << 0 << '\n';
    }

    void front(){
        if(!sizz) cout << -1 << '\n';
        else cout << head->value << '\n';
    }

    void back(){
        if(!sizz) cout << -1 << '\n';
        else cout << rear->value << '\n';
    }
};

queue <int> q;
int N;

int main(){
    cin >> N;

    string cmd;
    int num;
    while(N--){
        cin >> cmd;
        if(cmd == "push") cin >> num, q.push(num);
        else if(cmd == "pop") q.pop();
        else if(cmd == "size") q.size();
        else if(cmd == "empty") q.empty();
        else if(cmd == "front") q.front();
        else if(cmd == "back") q.back();
    }
}
