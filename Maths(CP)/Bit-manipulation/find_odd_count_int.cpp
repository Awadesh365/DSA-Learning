#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
    given array a of n integers. all integers
    are present in even count except one.
    find that one integer which has odd count
    in O(N) time complexity and O(1) space

     N<1e5
     a[i]<1e5

*/

int main()
{
    int n;
    cin >> n;
  
    int ans = 0;
    for (ll i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;

    return 0;
}