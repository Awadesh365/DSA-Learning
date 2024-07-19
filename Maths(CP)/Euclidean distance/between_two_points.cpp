#include <bits/stdc++.h>
using namespace std;

// distance[(x1​,y1​),(x2​,y2​)]^2=(x2​−x1​)^2+(y2​−y1​)^2
// in this case we are finding the maximum Euclidean Distance between two point, when we have given two vectors or arrays
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (auto &it : a)
        cin >> it;

    for (auto &it : b)
        cin >> it;

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = a[i] - a[j], y = b[i] - b[j];
            int distance = (x * x + y * y);

            ans = max(ans, distance);
        }
    }
    cout << ans << endl;
    return 0;
}