#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void find_KthLargest(Node *root, int &k, int &ans)
    {
        if (!root)
            return;

        find_KthLargest(root->right, k, ans);

        k--;
        if (k >= 0)
            ans = root->data;
        else
            return;

        find_KthLargest(root->left, k, ans);
    }

    int kthLargest(Node *root, int K)
    {
        int ans = INT_MAX;
        find_KthLargest(root, K, ans);

        return ans;
    }
};

int main()
{
    return 0;
}