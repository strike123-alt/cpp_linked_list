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
    cout << head->data << endl;   
    if(head->next == NULL) return;    
    display(head->next);
}


Node* delNodeBeg(Node* head){
    if(head == NULL)
        return NULL;
    Node *temp = head->next;
    delete head;
    return temp;
}
int main(){
    Node* a = NULL;
    a = delNodeBeg(a);
    display(a);
    return 0;
}