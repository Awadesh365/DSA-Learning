/*  Awadesh Nautiyal  */
// The Lost Cow Problem -> http://www.usaco.org/index.php?page=viewproblem2&cpid=735
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int x, y;
    cin >> x >> y;
    vector<int> zigzag;

    if (x == y)
        cout << "0" << endl;
    else if (x < y)
    {
        int distance = 1;

        while (x + distance < y)
        {
            zigzag.push_back(x + distance);
            distance *= -2;
        }
        zigzag.push_back(x + distance);

        int ans = 1;

        for (int i = 0; i < zigzag.size() - 1; i++)
        {
            ans += abs(zigzag[i] - zigzag[i + 1]);
        }
        ans -= (zigzag[zigzag.size() - 1] - y);
        cout << ans << endl;
    }
    else
    {
        int distance = 1;

        while (x + distance > y)
        {
            zigzag.push_back(x + distance);
            distance *= -2;
        }

        zigzag.push_back(x + distance);

        int ans = 1;

        for (int i = 0; i < zigzag.size() - 1; i++)
        {
            ans += abs(zigzag[i] - zigzag[i + 1]);
        }

        ans -= (y - zigzag[zigzag.size() - 1]);
        cout << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}