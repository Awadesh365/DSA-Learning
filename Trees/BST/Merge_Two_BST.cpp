#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
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

class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.

    void inorder(Node *root, vector<int> &arr)
    {
        if (!root)
            return;

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> arr1, arr2;

        inorder(root1, arr1);
        inorder(root2, arr2);

        vector<int> ans;

        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < arr1.size() && ptr2 < arr2.size())
        {
            if (arr1[ptr1] == arr2[ptr2])
            {
                ans.push_back(arr1[ptr1]);
                ans.push_back(arr2[ptr2]);
                ptr1++, ptr2++;
            }
            else if (arr1[ptr1] < arr2[ptr2])
            {
                ans.push_back(arr1[ptr1]);
                ptr1++;
            }
            else
            {
                ans.push_back(arr2[ptr2]);
                ptr2++;
            }
        }

        while (ptr1 < arr1.size())
        {
            ans.push_back(arr1[ptr1]);
            ptr1++;
        }
        while (ptr2 < arr2.size())
        {
            ans.push_back(arr2[ptr2]);
            ptr2++;
        }
        return ans;
    }
};