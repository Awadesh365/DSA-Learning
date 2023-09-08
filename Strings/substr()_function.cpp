#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "Welcomerstuv";

    int pos = 1;
    // copy the substring from indext pos +1 to the last of the string.
    cout << a.substr(pos + 1) << endl; // prints "elcomerstuv"

    // from index 0, copy next three elements in the string
    cout << a.substr(0, 3) << endl; // prints wel

    // from index 3, copy next three charaters in the string
    cout << a.substr(3, 3) << endl; // prints com
    return 0;
}