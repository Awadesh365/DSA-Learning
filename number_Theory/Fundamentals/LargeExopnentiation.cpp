#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Reference -> https://www.youtube.com/watch?v=vz0P_2V0y7M&list=PLauivoElc3giVROwL-6g9hO-LlSen_NaV&index=12

/**************************************** Large Binary Exoponentiation.**********************************************/
/*
Three Cases
1. When a is Too large with respect to b and m (MOD).
2. when m(MOD) is Too large with respect to a and b.
3. When b is Too large with respect to a and m (MOD). (m can be globle or in the function call)
*/

/*--------------------------------------------------*/
//                           1st
// When value of a is Too large with respect to b and m (MOD)
ll Large_BinPow1(ll a, ll b, ll m)
{
    // a = LargeBinExpo1(2, 1024, m); first do this step  if a is in the form of e.g (2^1024) like,
    a %= m; // from starting itself the value of a becomes smaller than m
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % m;

        a = (a * a) % m;
        b = (b >> 1);
    }
    return ans;
}
/*---------------------------------------------------*/
//                        2nd
// O((log(n))^2) complexity
// when value of m (MOD) is too large with respect to a and b
/*
NOTE:-
 we can't do direct multiplication in this case so we need to multiply indirectly,
  so we have to define a separate multiplication function for that.
*/

ll Large_BinPow2(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = Bin_Multiplication(ans, a, m); // Indirect multiplication

        a = Bin_Multiplication(a, a, m);
        b = (b >> 1);
    }
    return ans;
}
// function for multiplication in Large_BinPow2
ll Bin_Multiplication(ll a, ll b, ll m)
{
    ll ans = 0;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans + a) % m;

        a = (a + a) % m;
        b = (b >> 1);
    }
    return ans;
}
/*--------------------------------------------------*/
//                          3rd
// with respect to a and m, When value of b is Too Large directly or indeirectly eg a^(b^c).

ll Large_BinPow3(ll a, ll b, ll c)
{
}

/*-----------------------------------------------------*/

/************************************************ Any of the three would be helpful ************************************************/
int main()
{
}