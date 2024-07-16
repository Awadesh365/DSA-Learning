#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

/* Tree node structure  used in the program*/

class Box
{
public:
    bool BST;
    int size;
    int min, max;

    Box()
    {
        BST = 1;
        size = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution
{
public:
    Box *find(Node *root, int &Totalsize)
    {
        // root doesn't exist
        if (!root)
        {
            return new Box();
        }
        // root exist
        Box *Lefthead = find(root->left, Totalsize);
        Box *Righthead = find(root->right, Totalsize);

        if (Lefthead->BST && Righthead->BST && Lefthead->max < root->data && Righthead->min > root->data)
        {
            Box *head = new Box();
            head->size = 1 + Lefthead->size + Righthead->size;
            head->min = min(root->data, Lefthead->min);
            head->max = max(root->data, Righthead->max);
            Totalsize = max(Totalsize, head->size);
            return head;
        }
        else
        {
            Lefthead->BST = 0;
            return Lefthead;
        }
    }
    int largestBst(Node *root)
    {
        int Totalsize = 0;
        find(root, Totalsize);
        return Totalsize;
    }
};
