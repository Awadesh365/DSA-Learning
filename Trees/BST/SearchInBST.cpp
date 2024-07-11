#include <bits/stdc++.h>
using namespace std;

// https : // www.geeksforgeeks.org/problems/search-a-node-in-bst/1

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val)
{
    Node *temp = NULL;
    if (tree == NULL)
        return new Node(val);

    if (val < tree->data)
    {
        tree->left = insert(tree->left, val);
    }
    else if (val > tree->data)
    {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

// Time complexity : avg case O(height) and in the worst case O(n)
bool search(Node *root, int x)
{
    if (!root)
        return false;

    if (root->data == x)
        return true;

    else if (root->data < x)
        return search(root->right, x);
    else
        return search(root->left, x);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << search(root, s);
        cout << endl;
    }
}