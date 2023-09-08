#include <bits/stdc++.h>
using namespace std;

int main()
{
    // without nesting we can find maximum of three and so on.
    cout << max({0, 1, 2}) << endl; // max(max(counter[0],counter[1]),couner[2])
    cout << min({3, 32, 4423, 23}) << endl;
}
