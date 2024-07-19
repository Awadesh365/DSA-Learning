/*
https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

*/

#include <bits/stdc++.h>
using namespace std;

static bool pairCompare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    if (a.first.second != b.first.second)
        return a.first.second < b.first.second;

    return a.second < b.second;
}

int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<pair<int, int>, int>> x;

    for (int i = 0; i < n; i++)
        x.push_back({{start[i], end[i]}, i + 1});

    sort(x.begin(), x.end(), pairCompare); // works without passing the parameters, because static was used in the function,

    int last = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (x[i].first.first > last)
        {
            ans++;
            last = x[i].first.second;
        }
    }
    return ans;
}

int main()
{
}