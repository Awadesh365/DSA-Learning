// & - and operator , | -> or operator  , ^ -> xor operator,
// ~ -> tilda operator (it inverts whole binary number, i.e it converts all zerso into 1's and all 1's into zero's)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void printBinary(int num);

int main()
{
    int n = 9;
    int i = 3;

    // bit set ( n ki ith bit ko set karna hai)
    printBinary((n | (1 << i)));

    // bit unset (n ki ith bit ko unset karna hai)
    printBinary((n & (~(1 << i))));

    // toggle -> converts 1 to zero or zero to one of a binary number(the xor of the same bit is zero )
    printBinary(n ^ (1 << 3));

    // count number of setBits in a binary number
    ll k = __builtin_popcount(n);

    cout << k << endl;
    return 0;
}

void printBinary(int num)
{
    for (int i = 10; i >= 0; --i)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}