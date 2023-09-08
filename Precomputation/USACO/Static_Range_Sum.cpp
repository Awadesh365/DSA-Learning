// #include <bits/stdc++.h> //complexity of this code is O(n)
// using namespace std;
// #define ll long long

// const ll N = 1e5 + 5;
// ll pre_array[N];

// int main()
// {
//     ll n;
//     cin >> n;
//     ll t;
//     cin >> t;
//     ll a[n];
//     for (ll i = 1; i < n + 1; i++)
//     {
//         cin >> a[i];
//         pre_array[i] = pre_array[i - 1] + a[i];
//     }
//     while (t--)
//     {
//         ll sum = 0;
//         ll L, R;
//         cin >> L >> R;
//         cout << pre_array[R] - pre_array[L] << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)size(x)

using ll = long long;
using vl = vector<ll>;

vl psum(const vl &a)
{
    vl psum(sz(a) + 1);
    for (int i = 0; i < sz(a); ++i)
        psum[i + 1] = psum[i] + a[i];
    // or partial_sum(begin(a),end(a),begin(psum)+1);
    return psum;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vl a(N);
    for (ll &x : a)
        cin >> x;
    vl p = psum(a);
    for (int i = 0; i < Q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l] << "\n";
    }
}