// it returns the maximum sum of subarray from that array
// https : // cp-algorithms.com/others/maximum_average_segment.html#algorithm-description
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int a[n] = {-2, 45, 98, -4, 6};

    int ans = a[0], sum = 0, min_sum = 0;

    // alorithm
    for (int r = 0; r < n; ++r)
    {
        sum += a[r];
        ans = max(ans, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
    cout << ans << endl;
}