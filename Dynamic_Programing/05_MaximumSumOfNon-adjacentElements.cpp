#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber/description/

class Solution
{
private:
    // Method 1: Memoiation (Top Down) TC: O(N), SC: O(N)
    int memoiation(int curIdx, vector<int> &nums, vector<int> &dp)
    {
        if (curIdx == 0)
            return nums[curIdx];

        if (curIdx < 0)
            return 0;

        if (dp[curIdx] != -1)
            return dp[curIdx];

        int pick = nums[curIdx] + memoiation(curIdx - 2, nums, dp);
        int notPick = 0 + memoiation(curIdx - 1, nums, dp);

        return dp[curIdx] = max(pick, notPick);
    }

    // Method 2: tabulation (Bottom up) TC: O(N), SC: O(N)
    int tabulation(int curIdx, vector<int> &nums, vector<int> &dp)
    {
        dp[0] = nums[0];
        int pick = 0, notPick = 0;
        for (int i = 1; i <= curIdx; i++)
        {
            pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];

            notPick = 0 + dp[i - 1];

            dp[i] = max(pick, notPick);
        }
        return dp[curIdx];
    }
    // Method 3: s[ace optimization TC: O(N), SC: O(1)
    int opti(int curIdx, vector<int> &nums)
    {
        if (curIdx == 0)
            return nums[0];

        int prev = nums[0], prev2 = 0;

        for (int i = 1; i <= curIdx; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;

            int notPick = 0 + prev;

            int cur = max(pick, notPick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return memoiation(n - 1, nums, dp);
    }
};

int main()
{

    return 0;
}