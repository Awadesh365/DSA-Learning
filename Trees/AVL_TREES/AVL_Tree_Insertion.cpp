#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

// https://www.geeksforgeeks.org/problems/avl-tree-insertion/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution
{
public:
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

    // Insert function
    Node *insertToAVL(Node *root, int key)
    {
        // Perform the normal BST insert
        if (!root)
            return new Node(key);

        if (key < root->data)
        {
            root->left = insertToAVL(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = insertToAVL(root->right, key);
        }
        else
        {
            return root; // Duplicates not allowed
        }

        // Update height of this ancestor node
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

        // Get the balance factor of this ancestor node to check whether this node became unbalanced
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && key < root->left->data)
        {
            return rightRotation(root);
        }

        // Right Right Case
        if (balance < -1 && key > root->right->data)
        {
            return leftRotation(root);
        }

        // Left Right Case
        if (balance > 1 && key > root->left->data)
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }

        // Right Left Case
        if (balance < -1 && key < root->right->data)
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }

        // Return the (unchanged) node pointer
        return root;
    }
};
int main()
{
    return 0;
}