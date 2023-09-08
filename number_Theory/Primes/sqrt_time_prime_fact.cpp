// Prime Factrization Using Pollard's Rho Algorithm
// Time Complexity O(sqrt(n)*log(n))
// auxilliary Space O(1)

// Problem :-https://atcoder.jp/contests/abc284/tasks/abc284_d

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Pr_fact(ll n)
{
    ll p = 0, q = 0;
    for (ll i = 2; i * i * i <= n; i++)
    {
        if (n % i != 0)
            continue;

        if ((n / i) % i == 0)
        {
            p = i;
            q = (n / i / i);
        }
        else
        {
            q = i;
            p = (ll)sqrt(n / i);
        }
        break;
    }
    cout << p << " " << q << endl;
}

int main()
{
    ll tests;
    cin >> tests;
    while (tests--)
    {
        ll n;
        cin >> n;
        Pr_fact(n);
    }
    return 0;
}