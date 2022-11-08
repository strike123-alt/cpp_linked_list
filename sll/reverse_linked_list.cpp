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
Node* reverse_iter(Node* root){
    Node *p1 = root, *p2 = root, *p3 = root;
    p3 = p3->next->next;
    p2 = p2->next;
    p1->next = NULL;
    while(p2->next != NULL){
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if(p3->next != NULL)
            p3 = p3->next;
    }
    p2->next = p1;
    return p2;
}
Node* reverse_recurr(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* next_head = reverse_recurr(head->next);
    Node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return next_head;
}
Node* front_reverse_recurr(Node* root , Node* head){
  
    Node *p1 = head, *p2 = root, *p3 = root->next;
    p2->next = p1;    
    if( p3 == NULL || p2 == NULL ) return p2;
    front_reverse_recurr(p3, p2);
   

}
int main(){
    Node* root = new Node(100);
    root->next = new Node(200);
    root->next->next = new Node(300);
    root->next->next->next = new Node(400);
    root->next->next->next->next = new Node(500);
    root->next->next->next->next->next = new Node(600);
    root = front_reverse_recurr(NULL, NULL);
    display(root);
    return 0;
} 