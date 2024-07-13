// https://www.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1?page=1&difficulty%5B%5D=0&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
//-------------------- Method 1-------------------
// class Solution
// {
// public:
//     vector<int> ans;
//     void inorder(Node *root)
//     {
//         if (!root)
//             return;

//         inorder(root->left);
//         ans.push_back(root->data);
//         inorder(root->right);
//     }
//     vector<int> printNearNodes(Node *root, int low, int high)
//     {
//         vector<int> sol;
//         inorder(root);
//         for (auto &it : ans)
//             if (it <= high && it >= low)
//                 sol.push_back(it);

//         return sol;
//     }
// };
//-----------------------------------------------------
// Method 2
int n1, n2;
class Solution
{
public:
    void find(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        if ((root->data) > n1 && (root->data) > n2)
        {
            find(root->left, ans);
        }
        else if ((root->data) < n1 && (root->data) < n2)
        {
            find(root->right, ans);
        }
        else
        {
            find(root->left, ans);
            ans.push_back(root->data);
            find(root->right, ans);
        }
    }
    vector<int> printNearNodes(Node *root, int low, int high)
    {
        vector<int> ans;
        n1 = low, n2 = high;
        find(root, ans);
        return ans;
    }
};
int main()
{
    return 0;
}