#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 16;
    if ((n & (n - 1)))
        cout << "NO" << endl;
    else
        cout << "YES POWER OF 2" << endl;
    return 0;
}