// https : // leetcode.com/problems/missing-number/description/

#include <bits/stdc++.h>
using namespace std;

// Method 1 Time Comp: O(N LogN)

// int missingNumber(vector<int> &nums)
// {

//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i != nums[i])
//             return i;
//     }
//     return nums.size();
// }

// Method 2: time Complexity O(N)

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sumBy_formula = (n * (n + 1)) / 2;

    int arrSum = 0;

    for (auto &it : nums)
        arrSum += it;

    return sumBy_formula - arrSum;
}
