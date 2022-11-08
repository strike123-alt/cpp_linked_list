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

void display_cll(Node* head){
    if(head == NULL) return;
    cout << head->data << " ";
    for(Node* temp = head->next; temp != head; temp = temp->next)
        cout << temp->data << " ";
    cout << endl;
}

void display(Node* head){
    cout << head->data << " ";
    if(head->next == NULL)
        return ;
    display(head->next);
}

Node* del_k(Node* head, int x){
    if(head == NULL) return NULL;
    if(head->next == head){
        head->next = NULL;
        delete head;
        return NULL;
    }
    Node* temp = head;  
    if(x != 1){   
    for(int i = 1; i < x - 1; i++)
        temp = temp->next;        
        Node* t = temp->next->next;
        temp->next->next = NULL;
        delete temp->next;
        temp->next = t;
        return head;
    }    
    else{
        Node* t = head->next;
        for(temp = temp->next; temp->next != head; temp = temp->next);
        temp->next->next = NULL;
        delete temp->next;
        temp->next = t;
        return t;
    }   
}

int main()
{
    Node* root = new Node(100);
    root->next = new Node(200);
    root->next->next = new Node(300);
    root->next->next->next = new Node(400);
    root->next->next->next->next = root;
    display_cll(root);
    root = del_k(root, 1);
    display_cll(root);
    display(root);
    return 0;    
}

