#include <bits/stdc++.h>
using namespace std;

/*
  Note:- we can use globel boolean variable, and when condition satisfied, you can do flag = true, and make
  a condition if(flag==false) print else ignore that,
  but after this all the further fuction calls will gets wasted, we want to save those function calls,
  by not calling the function, when a subsequence is printed.
*/

bool print_ans(vector<int> &ans, vector<int> arr, int idx, int sz, int sum, int check)
{
    if (idx == sz)
    {
        if (check == sum)
        {
            for (auto &it : ans)
                cout << it << " ";

            return true; // after this the function will not go to further lines.
        }
        else // if there are no subsequences are there
            return false;
    }

    ans.push_back(arr[idx]);
    check += arr[idx];
    if (print_ans(ans, arr, idx + 1, sz, sum, check))
        return true;

    ans.pop_back();
    check -= arr[idx];
    if (print_ans(ans, arr, idx + 1, sz, sum, check))
        return true;

    return false;
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