#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFirstOccurence(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
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
    int findLastOccurence(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int ans1 = findFirstOccurence(nums, target);
        int ans2 = findLastOccurence(nums, target);

        return {ans1, ans2};
    }
};
int main()
{
    Solution s;

    vector<int> nums = {1, 2, 2, 3, 4};
    int target = 2;
    vector<int> ans = s.searchRange(nums, target);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}