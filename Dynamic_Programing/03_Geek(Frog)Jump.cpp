#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

class Solution
{
private:
    // Method 1: Memoiation (TOP down): TC:- O(N), SC:- O(N)
    int findMinimumMemoiation(vector<int> &height, int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int left = left = abs(height[n - 1] - height[n]) + findMinimumMemoiation(height, n - 1, dp);
        int right = INT_MAX;

        if (n >= 2)
            right = abs(height[n - 2] - height[n]) + findMinimumMemoiation(height, n - 2, dp);

        return dp[n] = min(left, right);
    }

    // Method 2: Tabulation (Bottom up): TC:- O(N), SC: O(N)
    int findEnergyTabulation(vector<int> &height, int n, vector<int> &dp)
    {
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int left = left = abs(height[i - 1] - height[i]) + dp[i - 1];
            int right = INT_MAX;
            if (i >= 2)
                right = abs(height[i - 2] - height[i]) + dp[i - 2];

            dp[i] = min(left, right);
        }
        return dp[n];
    }

    // Method 3: Optimal : TC:- O(N), SC: O(1)

    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n + 1, -1);
        // return optimal(height, n);

        if (n == 0)
            return 0;

        int prev = 0, prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int left = abs(height[i - 1] - height[i]) + prev;
            int right = INT_MAX;
            if (i > 1)
                right = abs(height[i - 2] - height[i]) + prev2;

            int cur = min(left, right);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n + 1, -1);
        return findMinimumMemoiation(height, n - 1, dp);
    }
};

int main()
{
    return 0;
}