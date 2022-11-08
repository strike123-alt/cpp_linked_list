#include<iostream>
using namespace std;
#define endl '\n'
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
void insAtBegin(Node* head, int data){
    Node* temp = head;
    head = new Node(data);
    head->next = temp;
    display(head);
}
void insAtEnd(Node* head, int data){
    if(head->next == NULL){
        head->next = new Node(data);
        display(head);       
        return ;
    }
    cout << head->data << endl;
    insAtEnd(head->next, data);
}
int main(){
    Node* a = new Node(10);
    a->next = new Node(20);
    a->next->next = new Node(30);
    a->next->next->next = new Node(40);
    Node* f = a;
    insAtBegin(f, 100);
    cout << "s" << endl;
    insAtEnd(f, 200);
    return 0;
}