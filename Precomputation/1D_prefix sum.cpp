/*
Given array A of N integers. Given Q queries
and in each query given L and R print sum of
array elements from index L to R(L,R included) (within O(n))

Constraints:
1<=N<=1e5
1<=a[i]<=1e9
1<=Q<=1e5
1<=L,R<=N

*/
// prefix sum
#include <bits/stdc++.h>          //complexity of this code is O(n)
using namespace std;
#define ll long long

const ll N = 1e5 + 5;
ll pre_array[N];   

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        pre_array[i] = pre_array[i - 1] + a[i];
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll sum = 0;
        ll L, R;
        cin >> L >> R;
        cout << pre_array[R] - pre_array[L - 1] << endl;
    }
    return 0;
}