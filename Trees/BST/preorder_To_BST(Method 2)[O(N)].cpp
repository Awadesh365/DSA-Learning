#include <bits/stdc++.h>
using namespace std;

/*
  Definition for a binary tree node.
*/

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    int minRangeVal = INT_MIN, maxRangeVal = INT_MAX;
    TreeNode *insert(vector<int> &preorder, int lower, int higher, int &index)
    {
        if (index == preorder.size() || preorder[index] < lower || preorder[index] > higher)
            return NULL;

        TreeNode *root = new TreeNode(preorder[index++]);
        root->left = insert(preorder, lower, root->val, index);
        root->right = insert(preorder, root->val, higher, index);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int index = 0, lower = INT_MIN, higher = INT_MAX;
        TreeNode *root = insert(preorder, lower, higher, index);
        return root;
    }
};

int main()
{
    return 0;
}