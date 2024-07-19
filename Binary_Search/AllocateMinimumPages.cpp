#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution
{
public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m)
    {
        if (m > n)
            return -1;

        int low = 0, high = 0;
        for (int i = 0; i < n; i++)
        {
            low = max(low, arr[i]);
            high += arr[i];
        }

        long long ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int numberOfStudents = 1;
            int curPages = 0;

            for (int i = 0; i < n; i++)
            {
                curPages += arr[i];
                if (curPages > mid)
                {
                    numberOfStudents++;
                    curPages = arr[i];
                }
            }
            /*
                why it is numberOfStudents <= m and not ==,
                because consider a case of[19, 9, 30, 22, 7],
                here the answer is 30, and m = 4,
                so in this case theortically distributing in the form of 19, 9, 30, 22 is not possible
                but logically if i can distribute to lesser number of
                students then i can distribute those pages in more number of students as well
                , eg if i can distribute these pages to 3 students
                then i can disribute them amoung 4 studnets as well.
            */
            if (numberOfStudents <= m)
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