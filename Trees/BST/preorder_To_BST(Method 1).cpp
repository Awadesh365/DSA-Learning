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
    TreeNode *insert(int curElement, TreeNode *root)
    {
        if (!root)
        {
            TreeNode *temp = new TreeNode(curElement);
            return temp;
        }
        if (curElement > root->val)
            root->left = insert(curElement, root->left);
        else
            root->right = insert(curElement, root->right);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode();
        for (auto &it : preorder)
        {
            root = insert(it, root);
        }
        return root;
    }
};

int main()
{
    return 0;
}