#include <bits/stdc++.h>
using namespace std;

// Method 1: Memoiation:- TC: O(N) , SC: O(N)
int fibo__Memo(vector<int> &dp, int n)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibo__Memo(dp, n - 1) + fibo__Memo(dp, n - 2);
}

// Method 2: Tabulation: TC O(N) , SC: O(N)
int fibo_Tabulation(vector<int> &dp, int n)
{
    dp[1] = 1, dp[0] = 0;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// Method 3: Space Optimization, TC: O(N), SC: O(1)
int fibo_Opti(int n)
{
    int prev = 1, prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main()
{

    int n;
    cin >> n;
    vector<int> memo_dp(n + 1, -1);
    cout << fibo__Memo(memo_dp, n) << endl;

    vector<int> tab_dp(n + 1, -1);
    cout << fibo_Tabulation(tab_dp, n) << endl;

    cout << fibo_Opti(n) << endl;

    return 0;
}