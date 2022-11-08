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

void display(Node* t){
    
    cout << t->data << " ";
    if(t->next == NULL)
        return ;
    display(t->next);
}


int main(){
    Node* root = new Node(10);
    Node* temp = root;
    root->next = new Node(20);
    root->next->prev = temp;
    temp = root->next;
    root->next->next = new Node(30);
    root->next->next->prev = temp;
    //display(root);
    cout << root->data << " " << root->next->data << " " << root->next->next->data << "\n";
    return 0;
}