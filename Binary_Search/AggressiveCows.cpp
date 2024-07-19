/*  Awadesh */
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/aggressive-cows/0

class Solution
{
private:
    bool canWePlace(int minimumDistance, int numberOf_CowsToPlace, vector<int> &stalls)
    {
        int numberOf_PlacedCows = 1;  // Place the first cow in the first stall
        int lastPosition = stalls[0]; // The position of the last placed cow

        // Try placing the rest of the cows
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - lastPosition >= minimumDistance)
            {
                numberOf_PlacedCows++;
                lastPosition = stalls[i];

                if (numberOf_PlacedCows == numberOf_CowsToPlace)
                {
                    return true; // Successfully placed all cows
                }
            }
        }

        return numberOf_PlacedCows >= numberOf_CowsToPlace;
    }

public:
    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end()); // Sort the stalls to apply binary search

        int low = 1;                          // Minimum possible distance
        int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
        int maximum_Distance = 0;             // Store the result

        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Middle point for binary search

            if (canWePlace(mid, k, stalls))
            {
                maximum_Distance = mid; // Update the result
                low = mid + 1;          // Try for a larger minimum distance
            }
            else
            {
                high = mid - 1; // Try for a smaller minimum distance
            }
        }

        return maximum_Distance; // The largest minimum distance
    }
};

int main()
{
    return 0;
}