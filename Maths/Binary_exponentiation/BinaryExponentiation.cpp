#include <bits/stdc++.h>
using namespace std;

// https : // practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1=power-of-numbers
/*
   SOLVED BY Using Binary Exponentiation Tecnique.
   this is an Classic Technique.

   */

int MOD = (1e9) + 7;
long long power(int N, int R)
{
    if (R == 0)
        return 1;

    long long value = power(N, R / 2) % MOD;
    value = (value * value) % MOD;

    if (R & 1)
        value = (value * N) % MOD;

    return value;
}

int main()
{
    int n, r;
    cin >> n >> r;

    cout << power(n, r);
}