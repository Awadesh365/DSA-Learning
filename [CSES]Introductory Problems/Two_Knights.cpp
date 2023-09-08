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
const ll N = 1e6;
void precompute()
{
}
ll attacking_knights(ll k)
{
    /*
     the attacking knights will be all the knights which lie inside the 2 X 3 + 3 X 2 area within our
      k X k cheesboard
      in a 3 X 2 or 2 X 3 Area the number of attacking combinations will be 2,
     */

    /*
    since the number of 3 X 2 area inside the k X k board will be horizontally(left,right) = (k-1) and vertically(up,down) = (k-2)
    similarly the number of 2 X 3 area inside the k X k board will be horizontally (k-1) and Vertically will be (k-2)

    and the attacking will be all_3X2 + all_2X3
    */
    ll hori_3X2 = (k - 1), verti_3X2 = (k - 2);
    ll hori_2X3 = (k - 2), verti_2X3 = (k - 1);

    ll all_3X2 = 2 * (hori_2X3 * verti_2X3);
    ll all_2X3 = 2 * (hori_3X2 * verti_3X2);

    return all_2X3 + all_3X2;
}
ll all_combinations(ll n)
{
    // here r=2, so we can simplify the formula
    // nCr =n!/r!*(n-r)!  = (n^2*(n^2-1))/2
    return ((n * n) * ((n * n) - 1)) / 2;
}
void solve()
{
    ll n;
    cin >> n;

    for (ll i = 1; i < n + 1; i++)
        cout << all_combinations(i) - attacking_knights(i) << endl;
}
int main()
{
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