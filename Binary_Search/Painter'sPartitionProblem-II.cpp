/*  Awadesh */
#include <bits/stdc++.h>
using namespace std;

//  NOTE: This problem is same as book allocation problem, with same code and same concept.

// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

class Solution
{
public:
    long long minTime(int arr[], int n, int k)
    {
        long long low = 0, high = 0;
        for (int i = 0; i < n; i++)
        {
            if (low < arr[i])
                low = arr[i];

            high += arr[i];
        }

        long long ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int numberOfPainters = 1;
            int curTime = 0;

            for (int i = 0; i < n; i++)
            {
                curTime += arr[i];
                if (curTime > mid)
                {
                    numberOfPainters++;
                    curTime = arr[i];
                }
            }
            /*
                why it is numberOfStudents <= m and not ==,
                because consider a case of[19, 9, 30, 22, 7],
                here the answer is 30, and m = 4,
                so in this case theortically distributing in the form of 19, 9, 30, 22 is not possible
                but logically if i can distribute to lesser number of
                painters then i can distribute those pages in more number of painters as well
                , eg if i can distribute these pages to 3 students
                then i can disribute them amoung 4 studnets as well.
            */
            if (numberOfPainters <= k)
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