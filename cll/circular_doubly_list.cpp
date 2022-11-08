#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node *prev, *next;
    Node(int data){
        this->data = data;
        next = prev = NULL; 
    }
};
void display(Node* head){
    if(head == NULL ) return;
    cout << head->data << " ";
    for(Node* temp = head->next; temp != head; temp = temp->next)
        cout << temp->data << " ";
    cout << endl;
}
void prev_display(Node* head){
    if(head == NULL ) return;
    Node* temp = head;
   
    for(temp = temp->prev; temp!= head; temp = temp->prev)
        cout << temp->data << " ";
    cout << temp->data << " ";
    cout << endl;
}

Node* insert_at_begin(Node* head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp; 
        temp->prev = temp;
        return temp;
    }   
    temp->prev = head->prev;
    temp->next = head;        
    head->prev->next = temp;
    head->prev = temp;
    return temp;
    
}

Node* insert_at_end(Node* head, int x){
    Node* temp = new Node(x);
    if(head == NULL){       
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    head->prev->next = temp;
    temp->prev = head;
    head->prev = temp;
    temp->next = head;
    return head;

    
}

int main(){
    Node *root = new Node(100);
    root->next = new Node(200);
    root->next->prev = root;
    root->next->next = new Node(300);
    root->next->next->prev = root->next;
    root->next->next->next = root; 
    root->prev = root->next->next;
    display(root);
    root = insert_at_begin(root, 400);
    display(root);
    root = insert_at_end(root, 500);
    display(root);
    return 0;
}