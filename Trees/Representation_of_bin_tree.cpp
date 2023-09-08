#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;

    NODE(int val)
    {
        data = val;
        left = NULL, right = NULL;
    }
};

int main()
{
    struct NODE *root = new NODE(1);
    root->left = new NODE(2);
    root->right = new NODE(3);
    root->left->right = new NODE(5);
    root->left->left = new NODE(6);
}