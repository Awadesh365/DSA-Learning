//  sieve of eratosthenes -> an algorithm to find a number is prime or not
// highest prime and lowest prime
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e6 + 10;
vector<bool> isPrime(N, 1); // storing prime numbers from 2 to N in vector
vector<ll> Low_prime(N, 0), High_prime(N, 0);

// sieve of eratosthenes method for primes
// O(log(log(n)))
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

int main()
{
    // int n;
    // cin >> n;

    Check_Prime();
    for (ll i = 0; i < 100; i++)
        cout << Low_prime[i] << " " << High_prime[i] << endl;
    // cout << isPrime[n];
    return 0;
}