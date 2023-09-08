/*  Awadesh Nautiyal  */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll N = 1e3+10;
ll arr[N][N], prefix[N][N];

void solve()
{
     ll n;
     cin>>n;
	
  for(ll i=1;i<n+1;i++)
    for(ll j=1;j<n+1;j++)
       cin>>arr[i][j];
  	
  for(ll i=1;i<n+1;i++)
  	for(ll j=1;j<n+1;j++)
  	prefix[i][j]=arr[i][j]+prefix[i-1][j] +prefix[i][j-1]-prefix[i-1][j-1];

  for(ll i=0;i<n+1;i++)
   {
    for(ll j=0;j<n+1;j++)
    {
      cout<<prefix[i][j]<<" ";
     }
    cout<<endl;
  }
  	
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
