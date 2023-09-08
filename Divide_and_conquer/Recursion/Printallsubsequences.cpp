#include <bits/stdc++.h>
using namespace std;

void subseq(vector<int> &ans, vector<int> arr, int idx, int sz)
{
    if (idx == sz)
    {
        for (auto it : ans)
            cout << it << " ";

        cout << endl;

        return;
    }
    // pick condition
    ans.push_back(arr[idx]);       // i am just printing the first one
    subseq(ans, arr, idx + 1, sz); // i have faith in you, that you can do pick and push_back, the next idx+1 conditions.

    // not pick condition
    ans.pop_back();                // i am removing the first one
    subseq(ans, arr, idx + 1, sz); // i have faith in you, that you can not pick and remove elements by yourself, the next idx+1 conditions.
}
int main()
{
    // {3,1,2}
    vector<int> arr = {3, 1, 2};
    vector<int> ans;
    subseq(ans, arr, 0, (arr.size()));

    return 0;
}