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

Node* insertAtEnd(Node* head, int data){
    Node *temp = new Node(data);
    if(head == NULL)
        return temp;
    Node *curr = head->next;
    while(curr->next != NULL){
        curr = curr->next;
    curr->next = temp;
        return head;
    }
}


int main(){
    Node* a = new Node(1);
    a->next = new Node(2);
    a->next->next = new Node(3);
    display(a);
    a = insertAtEnd(a, 100);
    display(a);
    return 0;
}