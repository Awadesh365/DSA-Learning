#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/climbing-stairs/description/

// Method 1: Memoiation (Top Down):-TC: O(N), SC: O(N)
int memoStairs(vector<int> &dp, int n)
{
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int oneStep = 0, twoSteps = 0;
    oneStep = memoStairs(dp, n - 1);
    if (n > 1)
        twoSteps = memoStairs(dp, n - 2);

    return dp[n] = oneStep + twoSteps;
}

// Method 2: Tabulation (Bottom up): TC: O(N), SC: O(N)
int tabuStairs(vector<int> &dp, int n)
{
    dp[1] = 1, dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}
// Method 3:  space optimization: TC: O(N), SC: O(1)
int optiStairs(int n)
{
    if (n <= 2)
        return n;

    int prev2 = 1, prev = 2;

    for (int i = 3; i <= n; i++)
    {
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int climbStairs(int n)
{
    // for memoiation (top down)
    vector<int> dp(n + 1, -1);
    return memoStairs(dp, n);

    // for tabulation (bottom up)
    vector<int> dp(n + 10, -1);
    return tabuStairs(dp, n);

    // space optimization
    return optiStairs(n);
}

int main()
{
    return 0;
}