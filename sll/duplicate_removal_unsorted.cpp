#include<iostream>
#include<vector>
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
Node* linked_list(vector<int> v){
    Node *head = new Node(v[0]), *temp = head;
    for(int i = 1; i < v.size(); i++){
        temp->next = new Node(v[i]);
        temp = temp->next;
    }
    return head;
}
Node* duplicate_node_rem(Node* head){
    if(head == NULL || head->next == NULL) return head;
    vector<int> original;
    Node* temp = head;
    bool check = true;
    while(temp != NULL){
        check = true;
        for(int i = 0; i < original.size(); i++)
        {
            if(original[i] == temp->data)
                check = false;
        }
        if(check)
            original.push_back(temp->data);
        temp = temp->next;
    }
    delete head;
    return linked_list(original);
}
int main(){
   Node* root = new Node(100);
   root->next = new Node(200);
   root->next->next = new Node(300);
   root->next->next->next = new Node(300);
   root->next->next->next->next = new Node(400); 
   root->next->next->next->next->next = new Node(500);
   root->next->next->next->next->next->next = new Node(400);
   display(duplicate_node_rem(root));
   return 0;
}
