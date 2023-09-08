#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e3 + 10;
ll arr[N][N];

ll prefix[N][N] = {0}; 

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            
            prefix[i][j] = prefix[i][i] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b, c, d; // (a,b) and (c,d)
        cin >> a >> b >> c >> d;
        cout << prefix[c][d] - prefix[a - 1][d] - prefix[c][b - 1] + prefix[a - 1][b - 1] << endl;
    }

    return 0;
}