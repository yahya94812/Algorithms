#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    Node *root;

    // insert method, return Node* and takes Node* for recursion
    Node *insert(Node *node, int val)
    {
        if (!node) // if root does't exist
        {
            return new Node(val);
        }

        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }
        // if val == root->data or above instructions executed
        return node;
    }

    Node *search(Node *node, int val)
    {
        if (!node || node->data == val)
        {
            return node;
        }
        if (val < node->data)
        {
            return search(node->left, val);
        }
        return search(node->right, val);
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    Node *find_min(Node *node)
    {
        while (node && node->left) // node to validate the root node this is the tree is exists
        {
            node = node->left;
        }
        return node;
    }

    Node *find_max(Node *node)
    {
        while (node && node->right) // node to validate the root node
        {
            node = node->right;
        }
        return node;
    }

    Node *remove(Node *node, int val)
    {
        if (!node)
            return node;

        if (val < node->data)
        {
            node->left = remove(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = remove(node->right, val);
        }
        else // perform deleting of the node
        {
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp; // executed only if deleting occur on that function call
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else // if both nodes are full
            {
                Node *temp = find_min(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        return node; // if deletion operation is not occur in that function call
    }
};

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "\nDeleting 20\n";
    tree.root = tree.remove(tree.root, 20);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "\nSearching for 60: ";
    Node *found = tree.search(tree.root, 60);
    if (found)
        cout << "Found!" << endl;
    else
        cout << "Not found!" << endl;

    return 0;
}