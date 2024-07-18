#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int size = 0;

    int findFirstOccurence(int nums[], int target)
    {
        int low = 0, high = size - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (target == nums[mid])
            {
                ans = mid;
                high = mid - 1;
            }
            else if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
    int findLastOccurence(int nums[], int target)
    {
        int low = 0, high = size - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + (high - low) / 2);
            if (target == nums[mid])
            {
                ans = mid;
                low = mid + 1;
            }
            else if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }

    int count(int nums[], int n, int target)
    {
        size = n;
        int ans1 = findFirstOccurence(nums, target);
        int ans2 = findLastOccurence(nums, target);

        if (ans1 == -1 || ans2 == -1)
            return 0;

        return ans2 - ans1 + 1;
    }
};
