#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = high + (low - high) / 2; // to avoid run time error in  the line '       else if (arr[mid] > arr[mid - 1]) '

            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                return mid;
            }
            else if (arr[mid] > arr[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return arr.size() - 1;
    }
};

int main()
{
    return 0;
}