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

const ll N = 1e6;
void precompute()
{
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = n - 1; i >= 0; i -= 2)
    {
        if (s[i] == s[i - 1])
            continue;
        if (s[i] == 'G' && (ans & 1))
            ans++;
        if (s[i] == 'H' && !(ans & 1))
            ans++;
    }
    cout << ans << endl;
}
int main()
{
    // setIO("");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // precompute();

    // ll TESTS;
    // cin >> TESTS;
    // while (TESTS--)
    solve();

    return 0;
}