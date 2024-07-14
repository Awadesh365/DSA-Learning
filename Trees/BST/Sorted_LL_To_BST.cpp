#include <bits/stdc++.h>
using namespace std;

/*
 Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 Definition for a binary tree TreeNode.
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
    TreeNode *buildBST(vector<int> Tree, int startIdx, int endIdx)
    {
        if (startIdx > endIdx)
            return NULL;

        int mid = (endIdx - startIdx + 1) / 2 + startIdx;
        TreeNode *root = new TreeNode(Tree[mid]);
        root->left = buildBST(Tree, startIdx, mid - 1);
        root->right = buildBST(Tree, mid + 1, endIdx);

        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> Tree;
        while (head)
        {
            Tree.push_back(head->val);
            head = (head->next);
        }

        int startIdx = 0, endIdx = Tree.size() - 1;
        TreeNode *BST = buildBST(Tree, startIdx, endIdx);

        return BST;
    }
};

int main()
{
    return 0;
}