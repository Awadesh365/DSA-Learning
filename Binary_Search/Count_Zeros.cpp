#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/count-the-zeros2550/1?page=1&difficulty

class Solution
{
public:
    int countZeroes(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        int initialIdx = high;
        while (low <= high)
        {
            int mid = (low + (high - low) / 2);
            if (arr[mid] == 0)
            {
                initialIdx = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return arr.size() - initialIdx;
    }
};

int main()
{
    return 0;
}