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

void display(Node* head){
    if(head == NULL) return;    
    cout << head->data << " ";
    for(Node* temp = head->next; temp != head; temp= temp->next)
        cout << temp->data << " ";
    cout << endl;
}

Node* insert_at_end(Node* head, int x){
    if(head == NULL){
        Node* temp = new Node(x);
        temp->next = temp;
        return temp;
    }
    Node* temp = head->next;
    for(;temp->next != head; temp = temp->next);
    Node* t = temp->next;
    temp->next = new Node(x);
    temp->next->next = t;
    return temp->next->next;
}
Node* insert_at_begin(Node* head, int x){
    if(head == NULL){
        Node* temp = new Node(x);
        temp->next = temp;
        return temp;
    }
    Node* temp = head->next;
    for(;temp ->next != head; temp = temp->next);
    Node* t = temp->next;
    temp->next = new Node(x);
    temp->next->next = t;
    return temp->next;
}
Node* del_at_begin(Node* head){
    if(head == NULL) return NULL;
    if(head->next == head){
        head->next = NULL;
        delete head;
        return NULL;
    }
    Node* temp = head->next;
    for(;temp->next != head; temp=temp->next);
    Node* t = temp->next->next;
    delete temp->next;
    temp->next = t;
    return temp->next;
}
int main()
{
    Node* root = new Node(100);
    root->next = new Node(200);
    root->next->next = new Node(300);
    root->next->next->next = new Node(400);
    root->next->next->next->next = root;
    //display(root);
    Node* root1 = insert_at_begin(root, 500);
    display(root1);
    root1 = del_at_begin(root1);
    display(root1);
    // Node* root2 = insert_at_end(root, 500);
    // display(root2);
    // root2 = del_at_begin(root2);
    //display(root2);
    return 0;
}