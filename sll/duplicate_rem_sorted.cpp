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
    cout << head->data << " ";
    if(head->next == NULL){
        cout << endl;
        return;
    }
    display(head->next);
}
Node* rem_of_duplicate_nodes(Node* head){
    Node *curr = head;
    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else
            curr = curr->next;
    }
    return head;
}

int main(){
    Node *root = new Node(100);
    root->next = new Node(100);
    // root->next->next = new Node(100);
    //root->next->next= new Node(200);
    // root->next->next->next->next = new Node(200);

    display(rem_of_duplicate_nodes(root));
}