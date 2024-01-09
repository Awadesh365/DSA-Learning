#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL, right = NULL;
    }
};

void inorder(node *myNode)
{
    if (myNode == NULL)
        return;

    inorder(myNode->left);
    cout << (myNode->data) << endl;
    inorder(myNode->right);
}

int main()
{
    node *root = new node(5);

    root->left = new node(6);
    root->left->left = new node(8);
    root->left->right = new node(9);
    root->left->right->left = new node(10);

    root->right = new node(7);
    root->right->left = NULL;

    inorder(root);

    return 0;
}