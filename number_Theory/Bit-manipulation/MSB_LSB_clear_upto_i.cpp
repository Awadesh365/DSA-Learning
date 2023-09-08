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
    // clear LSB upto ith bit
    int i = 4;
    int a = 59;

    int b = (a & (~((1 << (i + 1)) - 1)));
    printBinary(b);

    // clear MSB upto ith bit
    int j = 3;
    int k = (a & ((1 << (j + 1)) - 1));
    printBinary(k);

    return 0;
}