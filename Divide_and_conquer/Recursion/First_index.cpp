#include <iostream>
using namespace std;

int firstIndex(int arr[], int idx, int x, int n)
{

    if (idx == n)
        return -1;
    /*
    slow way
    int i = firstIndex(arr, idx + 1, x, n);
        if (arr[idx] == x)
            return idx;
        else
            return i;
    */

    // better way
    if (arr[idx] == x)
        return idx;
    else
    {
        int i = firstIndex(arr, idx + 1, x, n);
        return i;
    }
}

int main()
{
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = firstIndex(arr, 0, d, n);
    cout << p << endl;
}