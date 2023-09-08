// multiple recursive call
// concept of pre, in and post area in the eular recursion tree

#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
    if (n == 0)
        return;

    cout << "pre " << n << endl;
    fun(n - 1);
    cout << "IN " << n << endl;
    fun(n - 1);
    cout << "POST " << n << endl;
}

int main()
{
    int n;
    cin >> n;
    fun(n);
    return 0;
}