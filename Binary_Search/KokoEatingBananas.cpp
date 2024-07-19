/*  Awadesh */
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/koko-eating-bananas/description/
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        long long low = 1, high = *max_element(piles.begin(), piles.end());

        long long ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            long long curTime = 0;
            for (auto &it : piles)
            {
                curTime += ceil((double)it / (double)mid);
            }

            if (curTime <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}