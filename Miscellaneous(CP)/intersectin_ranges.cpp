// finding intersection between two ranges
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int preans = (b - a) + (d - c);

    int intersection = max(min(b, d) - max(a, c), 0);
    return 0;
}