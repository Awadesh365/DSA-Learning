#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

/*
 Definition for a binary tree node.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    class Box
    {
    public:
        bool BST;
        int size;
        int min;
        int max;
        int sum;
        Box() : BST(true), size(0), min(INT_MAX), max(INT_MIN), sum(0) {}
    };

    Box *find(TreeNode *root, int &maxSum)
    {
        // root doesn't exist
        if (!root)
        {
            return new Box();
        }

        // root exists
        Box *Lefthead = find(root->left, maxSum);
        Box *Righthead = find(root->right, maxSum);

        if (Lefthead->BST && Righthead->BST && Lefthead->max < root->val && Righthead->min > root->val)
        {
            Box *head = new Box();
            head->size = 1 + Lefthead->size + Righthead->size;
            head->min = min(root->val, Lefthead->min);
            head->max = max(root->val, Righthead->max);
            head->sum = root->val + Lefthead->sum + Righthead->sum;
            maxSum = max(maxSum, head->sum);
            return head;
        }
        else
        {
            Lefthead->BST = false;
            return Lefthead;
        }
    }
    int maxSumBST(TreeNode *root)
    {
        int maxSum = 0;
        find(root, maxSum);
        return maxSum;
    }
};