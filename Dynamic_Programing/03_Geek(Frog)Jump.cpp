#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

class Solution
{
private:
    // Methhod 1: Memoiation: TC:- O(N), SC:- O(N)
    int findMinimumEnergy(vector<int> &height, int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int left = left = abs(height[n - 1] - height[n]) + findMinimumEnergy(height, n - 1, dp);
        int right = INT_MAX;

        if (n >= 2)
            right = abs(height[n - 2] - height[n]) + findMinimumEnergy(height, n - 2, dp);

        return dp[n] = min(left, right);
    }

public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n + 1, -1);
        return findMinimumEnergy(height, n - 1, dp);
    }
};

int main()
{
    return 0;
}