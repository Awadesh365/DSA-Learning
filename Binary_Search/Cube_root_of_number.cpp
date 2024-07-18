#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int cubeRoot(int x)
    {
        int ans = 0;
        int low = 1, high = x;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int test = x / mid;

            if ((mid) == test / mid)
                return mid; // to avoid overflow during multiplication
                            // of mid*mid we have written it like that.
            else if (mid > test / mid)
                high = mid - 1;
            else
            {
                ans = (mid);
                low = mid + 1;
            }
        }

        return ans;
    }
};