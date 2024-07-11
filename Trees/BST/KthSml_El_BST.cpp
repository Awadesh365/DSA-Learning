#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    void find_KthSmallest(TreeNode *root, int &k, int &ans)
    {
        if (!root)
            return;

        find_KthSmallest(root->left, k, ans);

        k--;
        if (k >= 0)
            ans = root->val;
        else
            return;

        find_KthSmallest(root->right, k, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = INT_MAX;
        find_KthSmallest(root, k, ans);

        return ans;
    }
};

int main()
{
    return 0;
}