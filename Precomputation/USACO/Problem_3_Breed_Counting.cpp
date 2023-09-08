/*  Awadesh Nautiyal  */
#include <bits/stdc++.h>
#include <cstdio>
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
void setIO(string name = "")
{ // FastIO see General -> Fast Input and Output
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
void solve(vector<ll> h, vector<ll> g, vector<ll> j, ll q)
{

    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;

        cout << (h[y] - h[x]) << endl
             << (g[y] - g[x]) << endl
             << (j[y] - j[x]) << endl;
    }
}

void precompute(vector<ll> arr, ll n, ll q)
{
    vector<ll> h(n + 1), g(n + 1), j(n + 1);
    for (ll i = 0; i < arr.size(); i++)
    {
        h[i + 1] = h[i];
        g[i + 1] = g[i];
        j[i + 1] = j[i];

        ll x;
        cin >> x;
        if (x == 1)
            h[i + 1]++;
        if (x == 2)
            g[i + 1]++;
        if (x == 3)
            j[i + 1]++;
    }
    solve(h, g, j, q);
}
int main()
{
    // setIO("bcount");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &it : a)
        cin >> it;

    precompute(a, n, q);

    // ll TESTS;
    // cin >> TESTS;
    // while (TESTS--)

    return 0;
}