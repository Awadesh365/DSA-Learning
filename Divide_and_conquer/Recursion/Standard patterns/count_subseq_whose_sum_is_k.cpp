#include <bits/stdc++.h>
using namespace std;

int print_ans(vector<int> arr, int idx, int sz, int sum, int check)
{
    if (idx == sz)
    {
        if (check == sum)
            return 1;
        else
            return 0;
    }

    check += arr[idx];
    int left = print_ans(arr, idx + 1, sz, sum, check);

    check -= arr[idx];
    int right = print_ans(arr, idx + 1, sz, sum, check);

    return (left + right);
}
int main()
{
    int sum = 3;
    vector<int> arr(5);
    for (auto &it : arr)
        cin >> it;

    int check = 0;

    int count = print_ans(arr, 0, arr.size(), sum, check);
    cout << count << endl;

    return 0;
}