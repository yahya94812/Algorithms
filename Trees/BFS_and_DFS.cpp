// implementation of BFS and DFS on simple binary tree

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BFS, level order traversal
void BFS(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    cout << "BFS (level order): ";
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
    cout << endl;
}

// DFS, preorder Traversal (root, left, right)
void DFS(Node *root)
{
    if (!root)
        return;

    stack<Node *> st;
    st.push(root);

    cout << "DFS preorder: ";
    while (!st.empty())
    {
        Node *current = st.top();
        st.pop();
        cout << current->data << " ";

        if (current->right)
            st.push(current->right);
        if (current->left)
            st.push(current->left);
    }
    cout << endl;
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

    BFS(root);
    cout << "now DFS" << endl;
    DFS(root);

    return 0;
}
