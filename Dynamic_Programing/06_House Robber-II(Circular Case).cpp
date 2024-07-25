#include <bits/stdc++.h>
using namespace std;

/**
 *  NOTE: This is Only the follow up question of previous question, so just need to changed
 * a bit and everything will works fine.
 * here i have used the space optimization logic of previus one, with
 * handeling the cases of 1st and last seperatly menas, one array for 0 to n-2 (first to last element)
 * and one array for 1 to n-1 (2nd to last element)
 *
 */
class Solution
{
private:
    // Method 3: s[ace optimization TC: O(N), SC: O(1)
    int opti(vector<int> &nums)
    {
        int curIdx = nums.size();

        if (curIdx == 0)
            return 0;

        if (curIdx == 1)
            return nums[0];

        int prev = nums[0], prev2 = 0;

        for (int i = 1; i < curIdx; i++)
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
        if (n == 1)
            return nums[0];

        vector<int> first, second;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                first.push_back(nums[i]);

            if (i != n - 1)
                second.push_back(nums[i]);
        }

        return max(opti(first), opti(second));
    }
};

int main()
{
    return 0;
}