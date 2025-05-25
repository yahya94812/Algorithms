#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int value): data(value), left(nullptr), right(nullptr) {}
};

void DFS(Node *node){
    if(node){
        cout<<node->data<<" ";
        DFS(node->left);
        DFS(node->right);
    }
}

int main()
{
    // creating a tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout<<"DFS traversal"<<endl;
    DFS(root);
    cout<<endl;

    return 0;
}
