#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

// Function to get the height of the tree
int getHeight(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}

// Function to get balance factor of node
int getBalance(Node *root)
{
    if (!root)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

// Right rotation
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update heights
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + std::max(getHeight(child->left), getHeight(child->right));

    return child;
}

// Left rotation
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update heights
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + std::max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node *deleteNode(Node *root, int key)
{
    if (!root)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // leaf node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // 1 child node
        else if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right && !root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // both child exists
        else
        {
            // right size smallest elemetn
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, root->data);
        }
    }
    // update height

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // check the balance
    int balance = getBalance(root);

    // left side unbalance
    if (balance > 1)
    {
        // LL
        if (getBalance(root->left) >= 0)
            return rightRotation(root);
        // LR
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    // right sise unbalance
    if (balance < -1)
    {
        //  RR
        if (getBalance(root->right) <= 0)
            return leftRotation(root);
        // RL
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }

    return root;
}
