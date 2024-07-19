#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-missing-positive-number/

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1, ans = n;
        // ans = n for the case when all numbers are present and the array is sorted

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int curMissingNumbers = arr[mid] - mid - 1;
            if (curMissingNumbers >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        int missingNUmber = ans + k;

        return missingNUmber;
    }
};

int main()
{
    return 0;
}