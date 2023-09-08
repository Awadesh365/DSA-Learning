/*
Given T test cases and in each test case,
a number N is given.print its factorial(within O(n) complexcity).
for each test case % M
where M=10^9+7.

constraints
1<=T<=10^5
1<=N<=10^5
*/

#include <bits/stdc++.h> // complxeity of this code is O(n)
using namespace std;

#define ll long long

const ll M = 1e9 + 7;
const ll N = 1e5 + 5;
ll fact[N];

int main()
{
    ll t;
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % M;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fact[n] << endl;
    }
    return 0;
}
