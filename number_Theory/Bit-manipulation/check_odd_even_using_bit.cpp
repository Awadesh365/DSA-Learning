#include <bits/stdc++.h>
using namespace std;
#define ll long long
void printBinary(int num)
{
    for (int i = 10; i >= 0; --i)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main()
{
    for (ll i = 1; i < 10; i++)
    {
        printBinary(i);

        if (i & 1) // this is checking the even odd condition
            cout << "ODD" << endl;
        else
            cout << "Even" << endl;
    }

    return 0;
}