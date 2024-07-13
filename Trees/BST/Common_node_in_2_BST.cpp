#include <bits/stdc++.h>
using namespace std;

// https//www.geeksforgeeks.org/problems/print-common-nodes-in-bst/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

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

// Method 1
class Solution
{
public:
    void inorder(Node *root, vector<int> &arr)
    {
        if (!root)
            return;

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    vector<int> findCommon(Node *root1, Node *root2)
    {
        vector<int> first, second;
        inorder(root1, first);
        inorder(root2, second);

        vector<int> ans;

        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < first.size() && ptr2 < second.size())
        {
            if (first[ptr1] == second[ptr2])
            {
                ans.push_back(first[ptr1]);
                ptr1++;
                ptr2++;
            }
            else if (first[ptr1] < second[ptr2])
                ptr1++;
            else
                ptr2++;
        }

        return ans;
    }
};

int main()
{
    return 0;
}