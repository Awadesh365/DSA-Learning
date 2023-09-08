#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    for (ll i = 0; i <= 10; i++)
    {
        // 2^i ->(1<<n)=2^n
        cout << (1 << i) << endl;
    }
    return 0;
}