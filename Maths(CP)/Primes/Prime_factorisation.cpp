/*
Prime Factorisation of a number.
factors (which are prime) of a number.

  primes-> a number is called prime
  if it has only two divisor, 1 and itself
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e6 + 10;
// for third case
/*---------------------------------------------------------------------*/
int Check_Prime();
vector<bool> isPrime(N, 1); // storing prime numbers from 2 to N in vector
vector<ll> Low_prime(N, 0), High_prime(N, 0);
/*---------------------------------------------------------------------*/

// O(n) complexity
void First_Method(ll n)
{
    vector<ll> Prime_Factors;
    for (ll i = 2; i <= n; i++)
    {
        while ((n % i) == 0)
        {
            Prime_Factors.push_back(i);
            n /= i;
        }
    }
    for (auto &it : Prime_Factors)
        cout << it << " ";
}

// O(sqrt(n)) complexity
/*
  a property in which
  " for a composite number( non-prime number )
  before sqrt(n) minimum 1 prime number should exist "
*/
void Second_Method(ll n)
{
    vector<ll> Prime_Factors;
    for (ll i = 2; i <= sqrt(n); i++) //  or for (ll i = 2; (i * i) <= n; i++)
    {
        while ((n % i) == 0)
        {
            Prime_Factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        Prime_Factors.push_back(n);

    for (auto &it : Prime_Factors)
        cout << it << " ";
}

// using sieve method
void Third_Method(ll n)
{
    map<ll, ll> Prime_factors;
    while (n > 1)
    {
        ll prime_factor = High_prime[n];
        while ((n % prime_factor) == 0)
        {
            n /= prime_factor;
            Prime_factors[prime_factor]++;
        }
    }

    for (auto factor : Prime_factors)
    {
        cout << factor.first << " " << factor.second << endl;
    }
}

int main()
{
    ll n;
    cin >> n;

    // First_Method(n);
    // Second_Method(n);
    Check_Prime();
    Third_Method(n);
    return 0;
}

//----------------------------------------
int Check_Prime()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            Low_prime[i] = High_prime[i] = i;
            for (ll j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                High_prime[j] = i;
                if (Low_prime[j] == 0)
                    Low_prime[j] = i;
            }
        }
    }
    return 0;
}