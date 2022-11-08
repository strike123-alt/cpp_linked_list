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
int naive_count_node(Node* head){
    int count = 1;
    while(head->next != NULL){
        head = head->next;
        count = count + 1;
    }
    return count;
}
int nth_node(Node* head, int x){
    int count = naive_count_node(head) - x + 1;
    if(count <= 0)
        return -1;
    while(count > 1){
        head = head->next;
        count = count - 1;
    }
    return head->data;
}
int nth_node_wo(Node* head, int x){
    if(head == NULL) return -1;
    Node *r1 = head, *r2 = head; 
    int i = 0;    
    for(; i < x; i++, r1 = r1->next);
    if(i != x) return -1;
    
    while(r1 != NULL){
        r2 = r2->next;
        r1 = r1->next;        
    }
    return r2->data;

}

int main(){
    Node* a = new Node(1);
    a->next = new Node(2);    
    // a->next->next = new Node(3);
    // a->next->next->next = new Node(4);
    // a->next->next->next->next = new Node(5);
    int ac = nth_node_wo(a, 2);
    cout << ac << endl;
    return 0;
}