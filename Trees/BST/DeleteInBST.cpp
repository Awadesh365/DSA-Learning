#include <bits/stdc++.h>
using namespace std;

/**
  Definition for a binary tree node.
**/
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;

        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else
        {
            // leaf node
            if ((!root->right) && (!root->left))
            {
                delete root;
                return nullptr;
            }
            // 1 child exist
            // left child exist
            else if (!root->left)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            // right child exists
            else if (!root->right)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            // 2 child exist
            else
            {
                // find the greatest element from left
                TreeNode *child = root->left;
                TreeNode *parnet = root;

                while (child->right)
                {
                    parnet = child;
                    child = child->right;
                }
                if (root != root)
                {
                    parnet->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                else
                {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};

int main()
{
    return 0;
}