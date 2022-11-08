#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void display(Node* head){
    cout << head->data << endl;
    if(head->next == NULL) return; 
    display(head->next);
}

Node* delTail(Node* a){
    if(a == NULL or a == NULL)
        return NULL;
    Node *head = a;
    while(head->next->next != NULL)
        head = head->next;
    head->next = NULL;
    return a;
}

int main(){
    Node* a = new Node(10);
    a = delTail(a);
    display(a);
    return 0;
}