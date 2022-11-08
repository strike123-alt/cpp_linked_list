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

void display(Node* root){
    cout << root->data << " ";
    if(root->next == NULL)
        return ;
    display(root->next);
}

void prev_display(Node* root){
    while(root->next != NULL)
     root = root->next;
    while(root != NULL){
        cout << root->data << " ";
        root = root->prev;
    }
}

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node *prev = NULL, *curr = head;
    while(curr!=NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    } 
    return prev->prev;
}



int main(){
    Node* root = new Node(10);
    Node* temp = root;
    root->next = new Node(20);
    root->next->prev = temp;
    temp = root->next;
    root->next->next = new Node(30);
    root->next->next->prev = temp;
    display(root); cout << endl;
    root = reverse(root);
    display(root);
    return 0;
}