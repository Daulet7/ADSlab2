#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(head==nullptr){
        head=node;
        head->next = nullptr;
    }
    else if(p==0){
        node->next = head;
        head = node;
    }
    else{
        Node *l = head;
        for(int i = 0; i<p-1; i++){
            l = l->next;    
        }      
        if(l->next == nullptr){
            node->next = nullptr;
            l->next = node;
        }
        else{
            node->next = l->next;
            l->next = node;
        }
    }
    return head;
}
 
Node* remove(Node* head, int p){
    if(p==0){
        Node *del = head;
        head = head->next;
        delete del;
    }
    else{
        Node *l = head;
        for(int i = 0; i<p-1; i++){
            l = l->next;
        }
        Node *del = l->next;;
        l->next = l->next->next;
        delete del;
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    if(p1!=0){
        Node *l = head;
        for(int i = 0; i<p1-1; i++){
            l = l->next;
        }
        Node *rep = l->next;
        l->next = l->next->next;
        if(p2!=0){
            l=head;
            for(int i = 0; i<p2-1; i++){
                l = l->next;
            }       
            rep->next=l->next;
            l->next=rep;
        }
        else{
            rep->next = head;
            head = rep;
        }
    }
    else{
        if(head->next==nullptr){
            return head;
        }
        Node *rep = head;
        head = head->next;
        if(p2!=0){
            Node *l = head;
            for(int i = 0; i<p2-1; i++){
                l = l->next;
            }       
            rep->next=l->next;
            l->next=rep;
        }
        else{
            rep->next = head;
            head = rep;
        }
    }
    return head;
}
 
Node* reverse(Node* head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
    Node *point = head;
    while(point->next != nullptr){
        Node *move = point->next;
        point->next=point->next->next;
        move->next=head;
        head = move;
    }
    return head;
}
 
void print(Node* head){
    if(head == nullptr){
        cout << -1 << endl;
        return;
    }
    Node *pr = head;
    while(pr != nullptr){
        cout << pr->val << " ";
        pr=pr->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    if(head->next == nullptr){
        return head;
    }
    Node *end = head;
    while(end->next != nullptr){
        end = end->next;
    }
    for(int i =0; i<x; i++){
        Node *shift = head;
        head = head->next;;
        shift->next = nullptr;
        end->next = shift;
        end=shift;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    head = reverse(head);
    head = cyclic_left(head, x);
    head = reverse(head);
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}