/*
    methods to find divisors,
     count of divisors
     and sum of all divisors
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5 + 10;
// for third method
/*---------------------*/
vector<ll> divisors[N];
int sum[N];
/*---------------------*/

// O(n) complexity
void Divisors1(ll n)
{
    ll cnt = 0, sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        if ((n % i) == 0)
        {
            cout << i << " ";
            cnt++;
            sum += i;
        }
    }
    cout << endl
         << cnt << " " << sum << endl;
}

// O(sqrt(n)) Complexity
void Divisors2(ll n)
{
    ll cnt = 0, sum = 0;
    for (ll i = 1; i <= sqrt(n); i++) // or for (int i = 1; (i * i) <= n; i++)
    {
        if ((n % i) == 0)
        {
            cout << i << " " << (n / i) << " ";
            cnt++;
            sum += i;
            if ((n / i) != i)
            {
                cnt++;
                sum += (n / i);
            }
        }
    }
    cout << endl
         << cnt << " " << sum << endl;
}

// O(nlog(n)) Complexity -> using Prime Factorisation
void Divisors3(ll n)
{
    for (ll i = 2; i < N; ++i)
    {
        for (ll j = i; j < N; j += i)
        {
            divisors[j].push_back(i);
        }
    }
    for (ll i = 1; i < n; ++i)
    {
        for (auto div : divisors[i])
        {
            cout << div << " ";
        }
        cout << endl;
    }
}

int main()
{
    ll n;
    cin >> n;
    // Divisors1();
    //  Divisors2();

    Divisors3(n);
    return 0;
}