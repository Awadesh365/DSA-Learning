// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
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
    int ans = INT_MAX;
    int prev = INT_MIN;

    void findMinDist(TreeNode *root)
    {
        if (!root)
            return;

        minDiffInBST(root->left);

        if (prev != INT_MIN) // to avoid overflow in int use this if
            ans = min(ans, (root->val) - prev);

        prev = root->val;
        minDiffInBST(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        findMinDist(root);
        return ans;
    }
};

int main()
{
    return 0;
}