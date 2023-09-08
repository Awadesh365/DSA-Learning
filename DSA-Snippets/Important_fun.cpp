// Important Functions
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e6;

// for random number generation
/*---------------------------------------------------------*/
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*----------------------------------------------------------*/

/*--------------------------------*/

ll getRandomNumber(ll l, ll r);
int sieve_algorithm();
bool iscomposite(ll n);
int BinExpo(ll a, ll b, ll m);
ll modInverse(ll a, ll m);
bool isPalindrome(ll num);
bool isExist(vector<ll> vec, ll elem);
bool isSetBit(ll num, ll i);
vector<ll> returnBinary(ll num);
vector<ll> set_Bit(ll n, ll i);
vector<ll> unset_Bit(ll n, ll i);
void factorial();
int permutation(ll n, ll r);
int combination(ll n, ll r);

/*------------------------------------*/
// get radom number between l and r
ll getRandomNumber(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}
/*---------------------------------------------*/

/*---------------------------------------------*/
// snippet -> sieve
// returns true if the number is prime
vector<bool> isPrime(N, true);
// O(log(log(n)))
// sieve of eratosthenes method for primes
int sieve_algorithm()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            for (ll j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return 0;
}
/*------------------------------------------------------*/

/*-------------------------------------------------------*/
// returns true if a number is composite ( i.e non- prime)
bool iscomposite(ll n)
{
    bool ct = false;
    for (ll i = 2; i < n; i++)
    {
        if (n % i == 0)
            ct = true;
    }
    return ct;
}
/*------------------------------------------------------*/

/*------------------------------------------------------*/
// a^b mod m
// Binary exponentiation
int BinExpo(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll t = BinExpo(a, b / 2, m);
        return (t * t) % m;
    }
    else
    {
        ll t = BinExpo(a, (b - 1) / 2, m);
        t = (t * t) % m;
        return (t * a) % m;
    }
}
/*------------------------------------------------------*/

/*------------------------------------------------------*/
// Fermat little theorem
ll modInverse(ll a, ll m)
{
    return BinExpo(a, m - 2, m);
}
/*------------------------------------------------------*/

/*------------------------------------------------------*/
bool isPalindrome(ll num)
{
    ll rev = 0, rem, temp;
    temp = num;
    while (temp > 0)
    {
        rem = temp % 10;
        rev = (rev * 10) + rem;
        temp = temp / 10;
    }
    if (rev == num)
        return true;
    else
        return false;
}
/*------------------------------------------------------*/

/*-------------------------------------------------------*/
// returs whether or not a element is present in vector.
bool isExist(vector<ll> vec, ll elem)
{
    bool result = false;
    if (find(vec.begin(), vec.end(), elem) != vec.end())
    {
        result = true;
    }
    return result;
}
/*--------------------------------------------------*/

/*--------------------------------------------------*/
// returns true if a Bit in a Binary number is Set (1)
bool isSetBit(ll num, ll i)
{
    if ((num & (1 << i)) != 0)
        return true;
    else
        return false;
}
/*--------------------------------------------------*/

/*--------------------------------------------------*/
// vector<ll> ans = returnBinary(num);
vector<ll> returnBinary(ll num)
{
    vector<ll> a;
    for (int i = 10; i >= 0; --i)
        a.push_back(((num >> i) & 1));

    return a;
}
/*--------------------------------------------------*/

/*--------------------------------------------------*/
// set a bit in a binary number
// ith bit of number n
vector<ll> set_Bit(ll n, ll i)
{
    vector<ll> a = returnBinary(n | (1 << i));
    return a;
}
/*--------------------------------------------------*/

/*--------------------------------------------------*/
// unset a bit in a binary number
//  ith bit of number n
vector<ll> unset_Bit(ll n, ll i)
{
    vector<ll> a = returnBinary(n & (~(1 << i)));
    return a;
}
/*--------------------------------------------------*/

/*--------------------------------------------------*/
// finding Factorial
ll fact[N];
// finding factorial till maximum value i.e N in precomputation.
void factorial()
{
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % N;
}
/*-----------------------------------------------------*/

/*-----------------------------------------------------------------*/
// call the factorial function in precomputation before using this
//   nPr=factorial(n)/factorial(n-r)
int permutation(ll n, ll r)
{
    factorial();
    return (fact[n] / fact[n - r]);
}
/*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*/
// calculate combination
int combination(ll n, ll r)
{
    ll ans = 1;
    for (ll i = 1; i <= r; i++)
    {
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans;
}
/*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*/

int main()
{
    // sieve_algorithm();
    // cout << isPrime[4] << endl;
}