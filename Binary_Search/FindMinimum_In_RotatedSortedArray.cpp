#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;

        int ans = nums[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // left side sorted
            if (nums[mid] >= nums[0]) // NOTE: >= is required, in case like [2,1] consider it
                low = mid + 1;
            else // right side sorted
            {
                ans = min(nums[mid], ans);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int mian()
{
    return 0;
}