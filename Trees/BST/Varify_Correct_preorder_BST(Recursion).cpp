#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

// https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

class Solution
{
public:
    void insert(int preorder[], int lower, int higher, int &index, int size)
    {
        if (index == size || preorder[index] < lower || preorder[index] > higher)
            return;

        int value = preorder[index++];
        insert(preorder, lower, value, index, size);
        insert(preorder, value, higher, index, size);
    }

    int canRepresentBST(int preorder[], int size)
    {
        int index = 0, lower = INT_MIN, higher = INT_MAX;
        insert(preorder, lower, higher, index, size);
        return index == size;
    }
};

int main()
{
    return 0;
}