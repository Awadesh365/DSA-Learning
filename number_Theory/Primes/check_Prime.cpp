/*
Prime Check  of a number.
  primes-> a number is called prime
  if it has only two divisor, 1 and itself
*/
#include <bits/stdc++.h>
using namespace std;

// O(n) complexity
bool First_Method(int n)
{
    for (int i = 2; i < n; i++)
    {
        if ((n % i) == 0)
            return false;
    }
    return true;
}

// O(sqrt(n)) complexity
bool Second_Method(int n)
{
    for (int i = 2; i <= sqrt(n); i++) //   or for (int i = 2; i * i <= n;i++)
    {
        if ((n % i) == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << false << endl;
        return 0;
    }

    cout << Second_Method(n) << endl;
    return 0;
}