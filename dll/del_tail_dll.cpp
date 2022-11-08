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
Node* del_tail(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL) 
    {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;
    Node* t = temp->next;
    temp->next = NULL;
    t->prev = NULL;
    delete t;
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
    display(del_tail(root));
}
