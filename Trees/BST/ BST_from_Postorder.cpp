#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *insert(int post[], int lower, int higher, int &index, int size)
{
    if (index < 0 || post[index] < lower || post[index] > higher)
        return NULL;

    Node *root = new Node(post[index--]);
    root->right = insert(post, root->data, higher, index, size);
    root->left = insert(post, lower, root->data, index, size);

    return root;
}

Node *constructTree(int post[], int size)
{
    int index = size - 1, lower = INT_MIN, higher = INT_MAX;
    Node *root = insert(post, lower, higher, index, size);
    return root;
}

int main()
{
    return 0;
}