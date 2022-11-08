#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void display(Node* root){
    cout << root->data << " ";
    if(root == NULL)
        return;
    display(root->next);
}

int main(){
    Node* n1 = new Node(100);
    Node* n2 = new Node(200);
    Node* n3 = new Node(300);
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;
    display(n1);
}