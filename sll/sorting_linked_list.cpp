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
    cout << head->data << ' '; 
    if(head->next == NULL){
        cout << endl;
        return ;
    }
    display(head->next);   
}
Node* insert_sorted_node(Node *head, int x){
    Node* temp = new Node(x);
    if(head == NULL) return temp;    
    if(temp->data > x){
        temp->next = head;
        return temp;
    }
    Node* t = head;
    for(;t->next != NULL && t->next->data < x; t = t->next);   
    temp->next = t->next;
    t->next = temp;  
    return head;
}
int main(){
    Node* root = new Node(10);
    root->next = new Node(20);
    root->next->next = new Node(30);
    root->next->next->next = new Node(40);
    display(root);
    root = insert_sorted_node(root, 45);
    display(root);
    return 0;
}