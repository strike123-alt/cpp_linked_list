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
void traversal(Node* head){
    if(head == NULL) return;
    cout << head->data << ' ';
    Node *temp = head;
    for(temp = temp->next; temp != head; temp = temp->next)
        cout << temp->data << " ";
   
  
}
int main(){
    Node* root = new Node(100);
    root->next = new Node(200);
    root->next->next = new Node(300);
    root->next->next->next = root;
    traversal(root);
    return 0;
}