//to find kth smallest in array
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << endl;

    sort(a, a + n); //pahle array ko increasing order me sort kardo aur phir kth element print kar do.
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;

    cout << endl;

    int k;
    cin >> k;
    cout << endl;
    cout << a[k - 1] << endl;
}