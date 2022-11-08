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
void display(Node* root){
    cout << root->data << " ";
    if(root->next == NULL){
        cout << endl;
        return;
    }
    display(root->next);
}
Node* reverse_recurr_k(Node* root, int x){
    Node* 
}
int main(){
    Node* root = new Node(100);
    root->next = new Node(200);
    root->next->next = new Node(300);
    root->next->next->next = new Node(400);
    root->next->next->next->next = new Node(500);
    root->next->next->next->next->next = new Node(600);
    
    display(reverse_recurr_k(root, 3));
    return 0;
}