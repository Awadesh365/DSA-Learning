// https://www.geeksforgeeks.org/problems/fixed-two-TreeTreeNodes-of-a-bst/1?page=1&difficulty%5B%5D=2&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

/*
 */
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// space comp: O(1) and Time COmp: O(N): using morries Traversal

class Solution
{
public:
    void correctBST(struct Node *root)
    {
        Node *curr = NULL;
        Node *first = NULL, *second = NULL;
        Node *last = NULL, *present = NULL;

        while (root)
        {
            if (!root->left)
            {
                last = present;
                present = root;
                if (last && last->data > present->data)
                {
                    if (!first)
                        first = last;

                    second = present;
                }
                root = root->right;
            }
            else
            {
                curr = root->left;
                while (curr->right && curr->right != root)
                {
                    curr = curr->right;
                }
                if (!curr->right)
                {
                    curr->right = root;
                    root = root->left;
                }
                else
                {
                    curr->right = NULL;

                    last = present;
                    present = root;
                    if (last && last->data > present->data)
                    {
                        if (!first)
                            first = last;

                        second = present;
                    }
                    root = root->right;
                }
            }
        }
        swap(first->data, second->data);
    }
};

int main()
{
    return 0;
}