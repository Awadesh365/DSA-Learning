#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

class Solution
{
public:
    bool checkDeadEnd(Node *root, int lower, int upper)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
        {
            if (root->data - lower == 1 && upper - root->data == 1)
                return true;
            else
                return false;
        }
        bool left = checkDeadEnd(root->left, lower, root->data);
        bool right = checkDeadEnd(root->right, root->data, upper);

        return left || right;
    }
    bool isDeadEnd(Node *root)
    {
        return checkDeadEnd(root, 0, INT_MAX);
    }
};