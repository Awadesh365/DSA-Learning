// binary search implimentation using recursion
#include <bits/stdc++.h>
using namespace std;

int BIN_SEARCH(vector<int> arr, int target, int Left, int Right)
{
    if (Left > Right)
        return -1;

    int mid = (Left + Right) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return BIN_SEARCH(arr, target, mid + 1, Right);
    else
        return BIN_SEARCH(arr, target, Left, mid - 1);
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6, 7, 9, 10};
    int left = 0, right = 9;
    int target = 8;
    cout << BIN_SEARCH(arr, target, left, right) << endl;
    return 0;
}