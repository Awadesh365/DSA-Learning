
/*
     In This case, we don't have a, so This loop does nothing at the start.
     then c is (e >>= 1) which is short for (e = e >> 1), right shift e by one bit.
      It is basically divining e by 2 at every loop (throwing out remainders)
    */

ll binpow(ll b, ll e)
{
    ll ans = 1;

    for (;; e >>= 1) // or for (;; e /= 2) or  for(;e>0;e>>=1) or for(;;e= e >> 1)
    {
        if (e <= 0)
            break;

        if (e & 1)
            ans = (ans * b) % mod;
        b = (b * b) % mod;
    }
    return ans;
}