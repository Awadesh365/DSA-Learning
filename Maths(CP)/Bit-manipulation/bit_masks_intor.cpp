
// limitations of bit masks is it is applicable upto 64 bit  only in case of unsinged long long.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // to find the union of sets - or operator is used
    // bit mask of 0,1,2   = 7 i.e 0111
    cout << (1 | 2 | 4) << endl;
    // bit mask of 2,3    -> the 2nd bit is set which is = 4 in decimal and 3rd bit is set which is =8 in decimal
    cout << (4 | 8) << endl;

    cout << endl;

    // to find intersection of sets - and operator is used
    // common bit between 5 and 7
    cout << (7 & 5) << endl;
    // common bits between 8 and 7
    cout << (8 & 7) << endl;

    return 0;
}