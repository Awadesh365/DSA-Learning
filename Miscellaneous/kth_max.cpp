//to find kth largest in array
#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << endl;

    sort(a, a + n, compare); //pahle array ko decreasing order me sort kardo aur phir kth element print kar do.
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;

    cout << endl;

    int k;
    cin >> k;
    cout << endl;
    cout << a[k - 1] << endl;
}