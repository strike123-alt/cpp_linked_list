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

void prev_display(Node* root)
{
    while(!root->next == NULL){
        root = root->next;
    }
    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->prev;
    }
}

Node* insert_at_end(Node* root, int x){
    if(root == NULL)
        return (new Node(x));
    Node* temp = root;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* t = temp;
    temp->next = new Node(x);
    temp->next->prev = t;
    return root;
}

int main(){
    Node* root = new Node(100);
    root = insert_at_end(root, 200);
    root = insert_at_end(root, 300);
    root = insert_at_end(root, 400);
    display(root);
    cout << endl;
    prev_display(root);
    return 0;
}