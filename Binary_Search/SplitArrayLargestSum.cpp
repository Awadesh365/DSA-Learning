/*  Awadesh */
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// NOTE: This problem is same sa Book Allocation Problem

class Solution
{
public:
    int splitArray(int arr[], int n, int k)
    {
        int low = 0, high = 0;
        for (int i = 0; i < n; i++)
        {
            if (low < arr[i])
                low = arr[i];

            high += arr[i];
        }

        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int numberOfSubarrays = 1;
            int curSum = 0;

            for (int i = 0; i < n; i++)
            {
                curSum += arr[i];
                if (curSum > mid)
                {
                    numberOfSubarrays++;
                    curSum = arr[i];
                }
            }
            /*
                why it is numberOfStudents <= m and not ==,
                because consider a case of[19, 9, 30, 22, 7],
                here the answer is 30, and m = 4,
                so in this case theortically distributing in the form of 19, 9, 30, 22 is not possible
                but logically if i can distribute to lesser number of
                Subarrays then i can distribute those pages in more number of Subarrays as well
                , eg if i can distribute these pages to 3
                then i can disribute them amoung 4 as well.
            */
            if (numberOfSubarrays <= k)
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