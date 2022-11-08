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
    cout << head->data << ' ';
    if(head->next == NULL)
        return ;
    display(head->next);
}
int count_node(Node* head){
    int count = 0;
    for(;head != NULL; head = head->next, count++);
    cout << count << " ";
    return count;
}
int naive_middle_element(Node* head){
    if(head == NULL) return NULL;
    int count = count_node(head);
    for(int i = 0; i < count  / 2; i++, head = head->next);
    return head->data;
}
int efficient_sol(Node* head){
    if(head == NULL) return NULL;
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main(){
    Node* root = new Node(100);
    root->next = new Node(200);
    root->next->next = new Node(300);
    root->next->next->next = new Node(400); 
    root->next->next->next->next = new Node(500);
    root->next->next->next->next->next = new Node(600);
    //display(root);
    int middle = efficient_sol(root);
    cout << middle;
    cout << endl;
    return 0;
}