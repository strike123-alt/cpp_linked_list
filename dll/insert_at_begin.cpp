#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *prev, *next;
    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

void prev_display(Node* root)
{
    cout << root->data << " ";
    if(root->prev == NULL)
        return;
    prev_display(root->prev);
}

void display(Node* root){
    cout << root->data << " ";
    if (root->next == NULL){
        return;
    }
    display(root->next);
}

Node* insert_begin(Node* root, int x){
    
    Node* temp = new Node(x);
    temp->next = root;
    if (root != NULL)
        root->prev = temp;

    return temp;
}

int main()
{
    Node *root = NULL; 
    // Node *temp = root;
    // root->next = new Node(200);
    // root->next->prev = temp;
    // temp = root->next;
    // root->next->next = new Node(300);
    // root->next->next->prev = temp;

    Node *r = insert_begin(root, 200);
    r = insert_begin(r, 300);
    display(r);
    cout << endl;
    prev_display(root);
    return 0;
}