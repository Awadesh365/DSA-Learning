#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int findPos(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int prev = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                prev = mid + 1;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return prev;
    }

public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;

        return findPos(nums, target);
    }
};

int main()
{
    return 0;
}