/*  Awadesh Nautiyal  */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// For debugging
/*-------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
// END of Debugging
/*--------------------------------------------*/
const ll N = 1e3 + 10;
ll prefix[N][N], arr[N][N];

void solve()
{
    ll n, q;
    cin >> n >> q;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            char x;
            cin >> x;

            if (x == '*')
                arr[i + 1][j + 1] = 1;
            else
                arr[i + 1][j + 1] = 0;
            // or  arr[i + 1][j + 1] += x == '*';
        }
    }

    for (ll i = 1; i < n + 1; i++)
        for (ll j = 1; j < n + 1; j++)
            prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];

    // O(n^3):- so we need some better way of solving it

    // while (q--)
    // {
    //     ll cnt = 0;
    //     ll a, b, c, d;
    //     cin >> a >> c >> b >> d;

    //     for ()
    //     {
    //         for ()
    //         {
    //             // do operations and increase count
    //         }
    //     }

    //     cout << cnt << endl;
    // }

    while (q--)
    {
        ll a, b, c, d;
        cin >> a >> c >> b >> d;

        ll ans = prefix[b][d] - prefix[a - 1][d] - prefix[b][c - 1] + prefix[a - 1][c - 1];

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