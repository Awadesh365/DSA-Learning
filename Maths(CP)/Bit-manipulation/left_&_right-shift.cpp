#include <bits/stdc++.h>
using namespace std;

int main()
{
    // left shift
    // in the binary of 3 which is 1 1 one extra zero is added in the last and now it becomes  1 1 0
    cout << (3 << 1) << endl;

    // right shift
    // in the binary of 3 which is 1 1 the last element which is 1 in this case is removed.
    cout << (3 >> 1) << endl;

    return 0;
}