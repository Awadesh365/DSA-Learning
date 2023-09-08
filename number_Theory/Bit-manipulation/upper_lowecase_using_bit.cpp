#include <bits/stdc++.h>
using namespace std;

int main()
{
    // lower case to uppercase
    for (char i = 'a'; i <= 'z'; i++)
        cout << char(i | (' ')) << " "; // cout << char(i & (~(1 << 5))) << endl;

    cout << endl
         << endl;

    // uppercase to lowercase
    for (char i = 'A'; i <= 'Z'; i++)
        cout << char((i & ('_'))) << " "; // cout << char(i | (1 << 5)) << endl;

    return 0;
}