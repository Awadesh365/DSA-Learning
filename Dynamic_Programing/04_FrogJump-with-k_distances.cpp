#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

/*
NOTE: This is the follow up question to the previous question where it was asked to find the
two cases and now it's k cases.
*/

// Method 1: (Top down) TC: O(N), SC: O(N)
int memoiation(vector<int> &height, int n, int k, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (n - j >= 0)
        {
            int jumps = memoiation(height, n - j, k, dp) + abs(height[n] - height[n - j]);

            minSteps = min(minSteps, jumps);
        }
    }
    return dp[n] = minSteps;
}

// Method 2: (Bottom up): TC: O(N), SC: O(N)
int tabulation(vector<int> &heights, int n, int k, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jumps = dp[i - j] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, jumps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
}

// Method 3: Space optimization is not ueful as you have to store k values and in the worst case k can be as larger as n.

int minimizeCost(vector<int> &height, int n, int k)
{
    // for top down (memoiation)
    vector<int> dp(n + 1, -1);
    return memoiation(height, n, k, dp);

    // for bottom up (tabulation)
    vector<int> dp(n + 10, -1);
    return tabulation(height, n, k, dp);
}

int main()
{
    return 0;
}