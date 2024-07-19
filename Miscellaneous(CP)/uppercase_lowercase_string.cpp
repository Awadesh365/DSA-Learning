#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::toupper); // convert whole string into uppercase

    transform(s.begin(), s.end(), s.begin(), ::tolower); // convert whole string into lowercase

    cout << s << endl;
}