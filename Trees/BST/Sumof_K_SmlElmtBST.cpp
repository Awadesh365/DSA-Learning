//{ Driver Code Starts
// Initial Template for C++

// https://www.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1

void findSum(Node *root, int &k, int &curSum)
{
    if (!root)
        return;

    findSum(root->left, k, curSum);

    k--;
    if (k >= 0)
        curSum += root->data;
    if (k <= 0)
        return;

    findSum(root->right, k, curSum);
}
int sum(Node *root, int k)
{
    int curSum = 0;

    findSum(root, k, curSum);
    return curSum;
}

int main()
{

    return 0;
}
