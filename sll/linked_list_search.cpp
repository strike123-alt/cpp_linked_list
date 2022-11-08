#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *link;
    Node(int data){
        this->data = data;
        link = NULL;
    }
};
Node *rec_display(Node *root, int x)
{
    if (root == NULL)
        return NULL;
    else if (root->data == x)
    {
        cout << root->data;
        return root;
    }
    
   rec_display(root->link, x);
}
Node *iter_display(Node *root, int x)
{
    if (root == NULL)
        return NULL;
    Node *temp = root;
    while (temp->link != NULL)
    {
        if (temp->data == x)
        {
            cout << temp->data;
            return temp;
        }
        temp = temp->link;
    }
    return NULL;
}

int main()
{
    Node *root = new Node(100);
    root->link = new Node(200);
    root->link->link = new Node(300);
    root->link->link->link = new Node(400);
    root = rec_display(root, 400);
    cout << "Successful" << '\t' << root->data << endl;
    return 0;
}