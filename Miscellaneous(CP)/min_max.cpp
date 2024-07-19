#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int k, l;
    vector<long long int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        k = min(a[0], a[i]); //inbuild funtion to find minimum in array
        l = max(a[0], a[i]); //inbulid funtion to find maximum in array
    }
    cout << k << " " << l;
}