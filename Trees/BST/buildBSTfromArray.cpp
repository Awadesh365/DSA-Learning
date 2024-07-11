#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *&root, int curElement)
{
    if (!root)
    {
        Node *temp = new Node(curElement);
        return temp;
    }

    if (curElement >= root->data)
        root->right = insert(root->right, curElement);
    else
        root->left = insert(root->left, curElement);

    return root;
}
void printTree(Node *root)
{
    if (root == NULL)
        return;

    printTree(root->left);
    cout << (root->data) << endl;
    printTree(root->right);
}

int main()
{
    vector<int> arr = {10, 21, 3, 41, 5, 62, 7, 8};

    Node *root = nullptr;
    for (auto &curElement : arr)
        root = insert(root, curElement);

    printTree(root);

    return 0;
}