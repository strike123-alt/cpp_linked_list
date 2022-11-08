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
    cout << head->data << "\n";
    if(head->next == NULL) return;
    display(head->next);
}

Node* insAtGiven(int pos, int data, Node* head){
    
    if(head == NULL) return NULL;
    
    if(pos == 1) { Node* ins = new Node(data); ins->next = head; return ins;}

    int count = 1;
    Node* ins = head;
    while(count < pos - 1){
        if(ins->next == NULL && pos > 1)
            return NULL;
        ins = ins->next;
        count++;
    }
    Node* temp = ins->next;
    ins->next = new Node(data);
    ins->next->next = temp;
    return head;
}

int main(){
    Node* a = new Node(10);
    a->next = new Node(20);
    a->next->next = new Node(30);
    a->next->next->next = new Node(40);
    display(a);
    a = insAtGiven(6, 50, a);
    display(a);
    return 0;
}