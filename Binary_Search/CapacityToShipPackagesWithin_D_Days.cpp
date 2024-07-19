/*  Awadesh */
#include <bits/stdc++.h>
using namespace std;

// NOTE: THis problem is same as book allocation problem
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = 0, high = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            low = max(low, weights[i]);
            high += weights[i];
        }

        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int curDays = 1;
            int curWeight = 0;

            for (int i = 0; i < weights.size(); i++)
            {
                curWeight += weights[i];
                if (curWeight > mid)
                {
                    curDays++;
                    curWeight = weights[i];
                }
            }
            /*
               why it is curDays <= m and not ==,
               because consider a case of[19, 9, 30, 22, 7],
               here the answer is 30, and m = 4,
               so in this case theortically distributing in the form of 19, 9, 30, 22 is not possible
               but logically if i can distribute to lesser number of
               Days then i can distribute those pages in more number of Days as well
               , eg if i can distribute these pages to 3 Days
               then i can disribute them amoung 4 studnets as well.
           */
            if (curDays <= days)
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