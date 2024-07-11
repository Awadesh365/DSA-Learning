#include <bits/stdc++.h>
using namespace std;

/**
  Definition for a binary tree node.
**/

// https://leetcode.com/problems/validate-binary-search-tree/
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
    // 2nd method
    long long prev = LONG_MIN;
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;

        bool left = isValidBST(root->left);
        if (root->val <= prev)
            return false;
        else
            prev = root->val;
        bool right = isValidBST(root->right);

        return (left && right);
    }
};

int main()
{
    return 0;
}