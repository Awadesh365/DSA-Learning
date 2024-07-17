// https: // www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    void rotate(vector<int> &arr)
    {
        int temp = arr[arr.size() - 1];
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = temp;
    }
};