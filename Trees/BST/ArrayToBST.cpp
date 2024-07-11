#include <bits/stdc++.h>
using namespace std;

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
    TreeNode *insert(TreeNode *&root, int curElement)
    {
        if (!root)
        {
            TreeNode *temp = new TreeNode(curElement);
            return temp;
        }

        if (curElement >= root->val)
            root->right = insert(root->right, curElement);
        else
            root->left = insert(root->left, curElement);

        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        vector<int> sol = preorderReciver(nums);

        TreeNode *root = nullptr;
        for (auto &curElement : sol)
            root = insert(root, curElement);

        return root;
    }

    void createTree(vector<int> &arr, int start, int end, vector<int> &ans)
    {
        if (start > end)
            return;

        int mid = start + (end - start) / 2;
        ans.push_back(arr[mid]);
        createTree(arr, start, mid - 1, ans);
        createTree(arr, mid + 1, end, ans);
    }

    vector<int> preorderReciver(vector<int> &nums)
    {
        vector<int> ans;
        createTree(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};