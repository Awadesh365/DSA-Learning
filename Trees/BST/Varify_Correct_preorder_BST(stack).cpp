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
    int canRepresentBST(int arr[], int size)
    {
        stack<int> lower, upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int lowerBound, upperBound;

        int left, right;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < lower.top())
                return 0;

            while (arr[i] > upper.top())
            {
                upper.pop();
                lower.pop();
            }
            lowerBound = lower.top();
            upperBound = upper.top();
            lower.pop();
            upper.pop();

            lower.push(arr[i]);
            upper.push(upperBound);

            lower.push(lowerBound);
            upper.push(arr[i]);
        }
        return 1;
    }
};

int main()
{
    return 0;
}