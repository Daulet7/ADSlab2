#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
    string data;
    Node *next, *prev;

    Node(string data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class l{
    public:
    Node *front, *back;

    l(){
        front = nullptr;
        back = nullptr;
    }

    void add_front(string data){
        Node *node = new Node(data);
        if(front==nullptr){
            front = node;
            back = node;
        }
        else{
            node->next = front;
            node->prev = nullptr;
            front->prev = node;
            front = node;
        }
        cout << "ok" << '\n';
    }

    void add_back(string data){
        Node *node = new Node(data);
        if(back==nullptr){
            back = node;
            front = node;
        }
        else{
            node->prev = back;
            node->next = nullptr;
            back->next = node;
            back = node;
        }
        cout << "ok" << '\n';
    }

    void erase_front(){
        if(front==nullptr){
            cout << "error" << '\n';
            return;
        }
        else{
            cout << front->data << '\n';
            Node *del = front;
            front = front->next;
            if(front){
                front -> prev = nullptr;
            }
            else{
                back = nullptr;
            }
            delete del;
        }
    }

    void erase_back(){
        if(back==nullptr){
            cout << "error" << '\n';
            return;
        }
        else{
            cout << back->data << '\n';
            Node *del = back;
            back = back ->prev;
            if(back){
                back->next = nullptr;
            }
            else{
                front = nullptr;
            }
            delete del;
        }
    }

    void ffront(){
        if(front != nullptr){
            cout << front->data << '\n';
        }
        else{
            cout << "error" << '\n';
        }
    }

    void bback(){
        if(back != nullptr){
            cout << back->data << '\n';
        }
        else{
            cout << "error" << '\n';
        }
    }

    void clear(){
        if(front){        
            Node *del = front;        
            while(del){            
                Node *next = del->next;
                delete del;
                del = next;       
            } 
            front = nullptr;
            back = nullptr;       
        }
        cout << "ok" << '\n';
    }
};

int main(){
    l k;
    string b;
    while (cin >> b) {
        if (b == "add_front") {
            string x; 
            cin >> x; 
            k.add_front(x);
        } else if (b == "add_back") {
            string x; 
            cin >> x; 
            k.add_back(x);
        } else if (b == "erase_front") {
            k.erase_front();
        } else if (b == "erase_back") {
            k.erase_back();
        } else if (b == "front") {
            k.ffront();
        } else if (b == "back") {
            k.bback();
        } else if (b == "clear") {
            k.clear();
        } else if (b == "exit") {
            cout << "goodbye" << '\n';
            break;
        }
    }
    return 0;
}