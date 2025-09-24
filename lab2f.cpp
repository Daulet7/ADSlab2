#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class list{
    public:
    Node *back;
    Node *front;

    list() {
        back = NULL;
        front = NULL;
    }

    void push_back(int data){
        Node *node = new Node(data);
        if(back == NULL) {
            back = node;
            front = node;
        }
        else{
            back->next = node;
            node->prev = back;
            back = node;
        }
    }

    void insert(int data, int index){
        Node *node = new Node(data);
        Node *l = front;
        if(index == 0){
            node->next = front;
            front->prev = node;
            front = node;
            return;
        }
        else{
            for(int i = 0; i<index-1; i++){
                l = l->next;
            }
            Node *r = l->next;
            if(r==NULL){
                push_back(data);
                return;
            }
            l->next = node;
            node->prev = l;
            r->prev = node;
            node->next = r;
        }
    }

    void print(){
        Node *node = front;
        while(node!=NULL){
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main(){
    list massive;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        massive.push_back(a);
    }

    int b, ind;
    cin >> b;
    cin >> ind;
    massive.insert(b, ind);
    massive.print();

    return 0;
}