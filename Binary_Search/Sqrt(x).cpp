#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {

        int ans = 0;
        int low = 1, high = x;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if ((mid) == x / mid)
                return mid; // to avoid overflow during multiplication
                            // of mid*mid we have written it like that.
            else if (mid > x / mid)
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

int main()
{
    return 0;
}