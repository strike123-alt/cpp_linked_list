#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev, *next;
    Node(int data){
        this->data = data;
        prev = next = NULL;
    }
};
void display(Node* root){
    cout << root->data << " ";
    if (root->next == NULL){
        return;
    }
    display(root->next);
}
Node* del_head(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;    
}
int main(){
    Node* root = new Node(100);
    Node* temp = root;
    root->next = new Node(200);
    root->next->prev = temp;
    temp = root->next;
    root->next->next = new Node(300);
    root->next->next->prev = temp;    
    display(root);
    cout << endl;
    display(del_head(root));
}