#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid] && nums[mid] >= nums[0])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    return 0;
}