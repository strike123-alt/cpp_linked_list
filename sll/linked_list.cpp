#include<iostream>
using namespace std;
#define endl "\n"
class Node{
    public:
    int data;
    Node* next;    
    Node(int data){
        this->data = data;   
    }
};

void display(Node* head){ 
    cout << head->data << endl;   
    if(head->next == NULL) return;    
    display(head->next);
}

int main(){
    Node* a = new Node(5);    
    Node* b = new Node(6);
    Node* c = new Node(10);

    a->next = b;
    b->next = c;
    c->next = NULL;

    display(a);
    return 0;
}