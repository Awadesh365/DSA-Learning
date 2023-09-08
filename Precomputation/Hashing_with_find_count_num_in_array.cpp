/*
Given array A of N integers. given Q queries.
and in each query given a number X. print count
of that number in array.(within O(n)  complexity)

Constranints:
1<=N<=1e5
1<=Q<=1e5
1<=A[i]<=1e7       hashing works only when the size is less than or equal to 1e7

*/

// finding count of a number within O(n)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5 + 5;
const ll Q = 1e5 + 5;
ll A[N];
ll hash_array[N]; // global arrays are always zero initialzed

int main()
{
    ll n;
    cin >> n;
    ll temp[n] = {0};
    for (ll i = 0; i < n; i++)
    { // finding the count of a number
        cin >> A[i];
        hash_array[A[i]]++;
    }

    ll t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        cout << hash_array[x] << endl;
    }
    return 0;
}
