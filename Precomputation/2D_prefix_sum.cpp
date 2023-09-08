/*
Given 2d array of N*N integers.Given Q queries and
in each query given a,b,c and d.
print sum of square represented by (a,b) as
top left point and (c,d) as top bottom right
point

constraints
1<=N<= 10^3
1<=a[i][j]<=10^9
1<=Q<=10^5
1<=a,b,c,d<=N
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e3 + 10;
ll arr[N][N];
ll prefix[N][N]; // globlal arrays are zero based, so intially all the initial elements are zero

void precomputation()
{
    ll n;
    cin >> n;

    for (ll i = 1; i < n + 1; i++) // 1 based indexing is essential in case of 2D arrays to manage initial zeros and initial prefix sum
    {
        for (ll j = 1; j < n + 1; j++)
        {
            cin >> arr[i][j];
            // formula to calculate the prefix sum in 2D array
            prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
}

void solve()
{
    ll a, b, c, d; // (a,b) and (c,d)
    cin >> a >> b >> c >> d;
    cout << prefix[c][d] - prefix[a - 1][d] - prefix[c][b - 1] + prefix[a - 1][b - 1] << endl;
}
int main()
{
    precomputation();

    ll TESTS;
    cin >> TESTS;
    while (TESTS--)
        solve();

    return 0;
}