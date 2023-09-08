#include <bits/stdc++.h>
using namespace std;

void print_ans(vector<int> &ans, vector<int> arr, int idx, int sz, int sum, int check)
{
    if (idx == sz)
    {
        if (check == sum)
        {
            for (auto &it : ans)
                cout << it << " ";

            cout << endl;
        }

        return;
    }

    ans.push_back(arr[idx]);
    check += arr[idx];
    print_ans(ans, arr, idx + 1, sz, sum, check);

    ans.pop_back();
    check -= arr[idx];
    print_ans(ans, arr, idx + 1, sz, sum, check);
}
int main()
{
    int sum = 3;
    vector<int> arr(5);
    for (auto &it : arr)
        cin >> it;

    vector<int> ans;

    int check = 0;

    print_ans(ans, arr, 0, arr.size(), sum, check);

    return 0;
}